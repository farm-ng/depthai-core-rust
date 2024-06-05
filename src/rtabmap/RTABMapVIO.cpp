#include "depthai/rtabmap/RTABMapVIO.hpp"

#include "depthai/pipeline/Pipeline.hpp"

namespace dai {
namespace node {
std::shared_ptr<RTABMapVIO> RTABMapVIO::build() {
    alphaScaling = -1.0;
    odom.reset(rtabmap::Odometry::create());

    localTransform = rtabmap::Transform::getIdentity();

    rtabmap::Transform opticalTransform(0, 0, 1, 0, -1, 0, 0, 0, 0, -1, 0, 0);
    localTransform = localTransform * opticalTransform.inverse();

    input.setBlocking(false);
    input.setMaxSize(0);
    inputIMU.setMaxSize(1);
    inputIMU.setBlocking(false);
    inputRect.setBlocking(false);
    inputRect.setMaxSize(1);
    inputDepth.setBlocking(false);
    inputDepth.setMaxSize(1);
    if(useFeatures) {
        inputFeatures.setBlocking(false);
        inputFeatures.setMaxSize(1);
        inputs[featuresInputName] = inputFeatures;
    }
    inputIMU.addCallback(std::bind(&RTABMapVIO::imuCB, this, std::placeholders::_1));
    return std::static_pointer_cast<RTABMapVIO>(shared_from_this());
}
void RTABMapVIO::imuCB(std::shared_ptr<dai::ADatatype> msg) {
    auto imuData = std::static_pointer_cast<dai::IMUData>(msg);
    auto imuPackets = imuData->packets;
    for(auto& imuPacket : imuPackets) {
        auto& acceleroValues = imuPacket.acceleroMeter;
        auto& gyroValues = imuPacket.gyroscope;
        auto& rotValues = imuPacket.rotationVector;
        double accStamp = std::chrono::duration<double>(acceleroValues.getTimestampDevice().time_since_epoch()).count();
        double gyroStamp = std::chrono::duration<double>(gyroValues.getTimestampDevice().time_since_epoch()).count();
        accBuffer_.emplace_hint(accBuffer_.end(), accStamp, cv::Vec3f(acceleroValues.x, acceleroValues.y, acceleroValues.z));
        gyroBuffer_.emplace_hint(gyroBuffer_.end(), gyroStamp, cv::Vec3f(gyroValues.x, gyroValues.y, gyroValues.z));
        rotBuffer_.emplace_hint(rotBuffer_.end(), gyroStamp, cv::Vec4f(rotValues.i, rotValues.j, rotValues.k, rotValues.real));
    }
}

std::shared_ptr<dai::Buffer> RTABMapVIO::processGroup(std::shared_ptr<dai::MessageGroup> in) {
    if (in == nullptr) return nullptr;
    auto imgFrame = in->get<dai::ImgFrame>(rectInputName);
    auto depthFrame = in->get<dai::ImgFrame>(depthInputName);
    std::shared_ptr<dai::TrackedFeatures> features = nullptr;
    if(useFeatures) {
        features = in->get<dai::TrackedFeatures>(featuresInputName);
    }
    rtabmap::SensorData data;
    if(imgFrame != nullptr && depthFrame != nullptr) {
        if(!modelSet) {
            auto pipeline = getParentPipeline();
            getCalib(pipeline, imgFrame->getInstanceNum(), imgFrame->getWidth(), imgFrame->getHeight());
            modelSet = true;
        } else {
            double stamp = std::chrono::duration<double>(imgFrame->getTimestampDevice(dai::CameraExposureOffset::MIDDLE).time_since_epoch()).count();

            data = rtabmap::SensorData(imgFrame->getCvFrame(), depthFrame->getCvFrame(), model.left(), imgFrame->getSequenceNum(), stamp);

            std::vector<cv::KeyPoint> keypoints;
            if(features != nullptr){
                for(auto& feature : features->trackedFeatures) {
                    keypoints.emplace_back(cv::KeyPoint(feature.position.x, feature.position.y, 3));
                }
                data.setFeatures(keypoints, std::vector<cv::Point3f>(), cv::Mat());
            }

            cv::Vec3d acc, gyro;
            cv::Vec4d rot;
            std::map<double, cv::Vec3f>::const_iterator iterA, iterB;
            std::map<double, cv::Vec4f>::const_iterator iterC, iterD;
            if(accBuffer_.empty() || gyroBuffer_.empty() || rotBuffer_.empty() || accBuffer_.rbegin()->first < stamp || gyroBuffer_.rbegin()->first < stamp
               || rotBuffer_.rbegin()->first < stamp) {
            } else {
                // acc
                iterB = accBuffer_.lower_bound(stamp);
                iterA = iterB;
                if(iterA != accBuffer_.begin()) iterA = --iterA;
                if(iterA == iterB || stamp == iterB->first) {
                    acc = iterB->second;
                } else if(stamp > iterA->first && stamp < iterB->first) {
                    float t = (stamp - iterA->first) / (iterB->first - iterA->first);
                    acc = iterA->second + t * (iterB->second - iterA->second);
                }
                accBuffer_.erase(accBuffer_.begin(), iterB);

                // gyro
                iterB = gyroBuffer_.lower_bound(stamp);
                iterA = iterB;
                if(iterA != gyroBuffer_.begin()) iterA = --iterA;
                if(iterA == iterB || stamp == iterB->first) {
                    gyro = iterB->second;
                } else if(stamp > iterA->first && stamp < iterB->first) {
                    float t = (stamp - iterA->first) / (iterB->first - iterA->first);
                    gyro = iterA->second + t * (iterB->second - iterA->second);
                }
                gyroBuffer_.erase(gyroBuffer_.begin(), iterB);

                // rot
                iterD = rotBuffer_.lower_bound(stamp);
                iterC = iterD;
                if(iterC != rotBuffer_.begin()) iterC = --iterC;
                if(iterC == iterD || stamp == iterD->first) {
                    rot = iterD->second;
                } else if(stamp > iterC->first && stamp < iterD->first) {
                    float t = (stamp - iterC->first) / (iterD->first - iterC->first);
                    rot = iterC->second + t * (iterD->second - iterC->second);
                }
                rotBuffer_.erase(rotBuffer_.begin(), iterD);

                data.setIMU(
                    rtabmap::IMU(rot, cv::Mat::eye(3, 3, CV_64FC1), gyro, cv::Mat::eye(3, 3, CV_64FC1), acc, cv::Mat::eye(3, 3, CV_64FC1), imuLocalTransform));
            }
            rtabmap::OdometryInfo info;
            auto pose = odom->process(data, &info);
            pose = localTransform * pose * localTransform.inverse();
            auto out = std::make_shared<dai::TransformData>(pose);
            transform.send(out);
            passthroughRect.send(imgFrame);
            passthroughDepth.send(depthFrame);
            passthroughFeatures.send(features);
        }
    }
    return nullptr;
}


void RTABMapVIO::setParams(const rtabmap::ParametersMap& params) {
    odom.reset(rtabmap::Odometry::create(params));
}


void RTABMapVIO::getCalib(dai::Pipeline& pipeline, int instanceNum, int width, int height) {
    auto calibHandler = pipeline.getDefaultDevice()->readCalibration();

    auto cameraId = static_cast<dai::CameraBoardSocket>(instanceNum);
    model = calibHandler.getRTABMapCameraModel(cameraId, width, height, localTransform, alphaScaling);

    std::vector<std::vector<float>> imuExtr = calibHandler.getImuToCameraExtrinsics(cameraId, true);

    imuLocalTransform = rtabmap::Transform(imuExtr[0][0],
                                           imuExtr[0][1],
                                           imuExtr[0][2],
                                           imuExtr[0][3] * 0.01,
                                           imuExtr[1][0],
                                           imuExtr[1][1],
                                           imuExtr[1][2],
                                           imuExtr[1][3] * 0.01,
                                           imuExtr[2][0],
                                           imuExtr[2][1],
                                           imuExtr[2][2],
                                           imuExtr[2][3] * 0.01);

    imuLocalTransform = localTransform * imuLocalTransform;
}
}  // namespace node
}  // namespace dai