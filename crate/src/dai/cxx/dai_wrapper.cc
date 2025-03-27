#include "src/dai/cxx/dai_wrapper.h"

#include "depthai_core_rust/src/dai/cxx.rs.h"

namespace dai {

/**
 * @brief Retrieves a list of all available devices.
 *
 * This function queries all connected devices and returns their identifiers.
 * If a device has a non-empty `mxid`, it is preferred and added to the list.
 * Otherwise, the device's name, which could be an IP or USB port name, is used.
 *
 * @return A vector of strings containing the identifiers of all available devices.
 */
rust::Vec<rust::String> get_all_available_devices() {
    rust::Vec<rust::String> devices;
    for(auto& info : dai::XLinkConnection::getAllConnectedDevices(XLinkDeviceState_t::X_LINK_ANY_STATE, false)) {
        if(!info.mxid.empty()) {
            // prefer maxid if available
            devices.push_back(info.mxid);
        } else {
            // name is ip or usb port name
            devices.push_back(info.name);
        }
    }
    return devices;
}

/**
 * @brief Opens a device with the given identifier and USB mode.
 *
 * This function creates a shared pointer to a `Device` object using the provided identifier
 * and USB mode settings.
 *
 * @param oak_id The identifier for the device.
 * @param usb2_mode Whether to use USB 2.0 mode.
 * @return A pointer to the opened device.
 */
dai::Device* open_device(rust::Str const oak_id, bool usb2_mode) {
    // Can accept mxid, ip address or usb port name
    DeviceInfo info = DeviceInfo(std::string(oak_id));
    auto usb_speed = !usb2_mode ? dai::UsbSpeed::SUPER_PLUS : dai::UsbSpeed::HIGH;
    try {
        auto device = new dai::Device(dai::OpenVINO::Version::VERSION_2022_1, info, usb_speed);
        return device;
    } catch (const std::exception& e) {
        return nullptr;
    }
}

/**
 * @brief Gets the encoding profile for the given quality for the H264 encoder.
 *
 * @note The default profile is H264_BASELINE.
 * @param quality The quality to get the encoding profile for.
 * @return The encoding profile.
 */
dai::VideoEncoderProperties::Profile get_encoding_profile(cxxOakCameraEncodingQuality const& quality) {
    switch (quality) {
        case cxxOakCameraEncodingQuality::Baseline:
            return dai::VideoEncoderProperties::Profile::H264_BASELINE;
        case cxxOakCameraEncodingQuality::Main:
            return dai::VideoEncoderProperties::Profile::H264_MAIN;
        case cxxOakCameraEncodingQuality::High:
            return dai::VideoEncoderProperties::Profile::H264_HIGH;
        default:
            return dai::VideoEncoderProperties::Profile::H264_HIGH;
    }
}

dai::VideoEncoderProperties::RateControlMode to_rate_control_mode(
    cxxEncodingRateControlMode mode) {
  switch (mode) {
    case cxxEncodingRateControlMode::Cbr:
      return dai::VideoEncoderProperties::RateControlMode::CBR;
    case cxxEncodingRateControlMode::Vbr:
      return dai::VideoEncoderProperties::RateControlMode::VBR;
    default:
      return dai::VideoEncoderProperties::RateControlMode::CBR;
  }
}

/**
 * @brief Creates a pipeline for recording with encoding.
 *
 * @param options Configuration options for the pipeline.
 * @return A pointer to the configured pipeline.
 */
dai::Pipeline* make_pipeline_encoding(cxxPipelineOptions const& options) {

    // parse the quality for the encoder
    dai::VideoEncoderProperties::Profile encoding_profile = get_encoding_profile(options.encoding_quality);
    dai::VideoEncoderProperties::RateControlMode encoding_rate_control_mode = to_rate_control_mode(options.encoding_rate_control_mode);

    // build the pipeline

    auto pipeline = new dai::Pipeline();

    // node to change the camera settings
    auto control_in = pipeline->create<dai::node::XLinkIn>();
    control_in->setStreamName("control");

    if (options.enable_cam_color) {
        std::shared_ptr<dai::node::ColorCamera> cam_color = pipeline->create<dai::node::ColorCamera>();
        cam_color->setBoardSocket(dai::CameraBoardSocket::CAM_A);  // this should be the center camera
        cam_color->setResolution(dai::ColorCameraProperties::SensorResolution::THE_1080_P);
        cam_color->setFps(options.camera_color_fps);

        auto xout_color = pipeline->create<dai::node::XLinkOut>();
        xout_color->setStreamName("cam_color");

        auto enc_color = pipeline->create<dai::node::VideoEncoder>();
        enc_color->setDefaultProfilePreset(cam_color->getFps(), encoding_profile);
        enc_color->setBitrateKbps(options.encoding_bitrate_kbps);
        enc_color->setRateControlMode(encoding_rate_control_mode);
        enc_color->setQuality(options.encoding_vbr_quality);
        enc_color->setKeyframeFrequency(options.encoding_frames_per_keyframe);

        cam_color->video.link(enc_color->input);
        enc_color->bitstream.link(xout_color->input);

        control_in->out.link(cam_color->inputControl);
    }

    if (options.enable_cam_left_mono) {
        std::shared_ptr<dai::node::MonoCamera> cam_left = pipeline->create<dai::node::MonoCamera>();
        cam_left->setBoardSocket(dai::CameraBoardSocket::CAM_B);  // this should be the left camera
        cam_left->setResolution(dai::MonoCameraProperties::SensorResolution::THE_800_P);
        cam_left->setFps(options.camera_mono_fps);

        auto xout_left = pipeline->create<dai::node::XLinkOut>();
        xout_left->setStreamName("cam_mono_left");

        auto enc_left = pipeline->create<dai::node::VideoEncoder>();
        enc_left->setDefaultProfilePreset(cam_left->getFps(), encoding_profile);
        enc_left->setBitrateKbps(options.encoding_bitrate_kbps);
        enc_left->setRateControlMode(encoding_rate_control_mode);
        enc_left->setQuality(options.encoding_vbr_quality);
        enc_left->setKeyframeFrequency(options.encoding_frames_per_keyframe);

        cam_left->out.link(enc_left->input);
        enc_left->bitstream.link(xout_left->input);

        control_in->out.link(cam_left->inputControl);
    }

    if (options.enable_cam_right_mono) {
        std::shared_ptr<dai::node::MonoCamera> cam_right = pipeline->create<dai::node::MonoCamera>();
        cam_right->setBoardSocket(dai::CameraBoardSocket::CAM_C);  // this should be the right camera
        cam_right->setResolution(dai::MonoCameraProperties::SensorResolution::THE_800_P);
        cam_right->setFps(options.camera_mono_fps);

        auto xout_right = pipeline->create<dai::node::XLinkOut>();
        xout_right->setStreamName("cam_mono_right");

        auto enc_right = pipeline->create<dai::node::VideoEncoder>();
        enc_right->setDefaultProfilePreset(cam_right->getFps(), encoding_profile);
        enc_right->setBitrateKbps(options.encoding_bitrate_kbps);
        enc_right->setRateControlMode(encoding_rate_control_mode);
        enc_right->setQuality(options.encoding_vbr_quality);
        enc_right->setKeyframeFrequency(options.encoding_frames_per_keyframe);

        cam_right->out.link(enc_right->input);
        enc_right->bitstream.link(xout_right->input);

        control_in->out.link(cam_right->inputControl);
    }

    // assign the imu to the pipeline
    std::shared_ptr<dai::node::IMU> imu = pipeline->create<dai::node::IMU>();
    if (options.imu_use_raw) {
        imu->enableIMUSensor({
            dai::IMUSensor::ACCELEROMETER_RAW,
            dai::IMUSensor::GYROSCOPE_RAW
        }, options.imu_report_rate_hz);
    } else {
        imu->enableIMUSensor({
            dai::IMUSensor::ACCELEROMETER,
            dai::IMUSensor::GYROSCOPE_UNCALIBRATED
        }, options.imu_report_rate_hz);
    }
    imu->setBatchReportThreshold(options.imu_batch_report_threshold);
    imu->setMaxBatchReports(options.imu_max_batch_reports);

    auto xout_imu = pipeline->create<dai::node::XLinkOut>();
    xout_imu->setStreamName("imu");
    imu->out.link(xout_imu->input);


    return pipeline;
}

/**
 * @brief Starts the depthai pipeline on the given device.
 *
 * @param device The device on which to start the pipeline.
 * @param pipeline The pipeline to start.
 * @return True if the pipeline was started successfully, false otherwise.
 */
bool start_pipeline(dai::Device* device, dai::Pipeline* pipeline) {
    return device->startPipeline(*pipeline);
}

/**
 * @brief Gets an output queue from the device with the given name.
 *
 * @param device The device from which to get the output queue.
 * @param name The name of the output queue.
 * @param max_capacity The maximum capacity of the output queue.
 * @param blocking Whether the output queue should block when full.
 * @return A pointer to the output queue.
 */
dai::DataOutputQueue* get_output_queue(dai::Device* device, rust::Str const name, uint32_t max_capacity, bool blocking) {
    return device->getOutputQueue(std::string(name), max_capacity, blocking).get();
}

/**
 * @brief Gets an input queue from the device with the given name.
 *
 * @param device The device from which to get the input queue.
 * @param name The name of the input queue.
 * @param max_capacity The maximum capacity of the input queue.
 * @param blocking Whether the input queue should block when full.
 * @return A pointer to the input queue.
 */
dai::DataInputQueue* get_input_queue(dai::Device* device, rust::Str const name, uint32_t max_capacity, bool blocking) {
    return device->getInputQueue(std::string(name), max_capacity, blocking).get();
}

/**
 * @brief Tries to get an image frame from the given output queue.
 *
 * If no frame is available, a null pointer is returned to skip the tick in the codelet.
 *
 * @param queue The output queue from which to get the image frame.
 * @return The result of the operation which indicates if the frame was successfully retrieved.
 */
TryGetResult try_get_image_frame(dai::DataOutputQueue* queue, rust::Slice<uint8_t> dst_data, cxxImageFrameInfo& frame_info) {
    std::shared_ptr<dai::ImgFrame> img_frame = nullptr;
    try {
        img_frame = queue->tryGet<dai::ImgFrame>();
    } catch (const std::exception& e) {
        return TryGetResult::QueueError;
    }

    if(!img_frame) {
        // no frame found, so we return a null pointer to skip the tick in the codelet
        return TryGetResult::TryAgain;
    }

    auto& data_vec = img_frame->getData();
    if(data_vec.size() > dst_data.size()) {
        return TryGetResult::InvalidSize;
    }

    // give ownership of the data to the destination vector
    std::move(data_vec.begin(), data_vec.end(), dst_data.begin());

    // get the timestamp and sequence number to set in the message
    frame_info.timestamp = std::chrono::duration<double>(img_frame->getTimestamp().time_since_epoch()).count();
    frame_info.sequence_number = img_frame->getSequenceNum();
    frame_info.exposure_time_us = img_frame->getExposureTime().count();
    frame_info.iso_sensitivity = img_frame->getSensitivity();
    frame_info.available_bytes = data_vec.size();

    return TryGetResult::Ok;
}

/**
 * @brief Tries to get an IMU frame from the given output queue.
 *
 * If no frame is available, a null pointer is returned to skip the tick in the codelet.
 *
 * @param queue The output queue from which to get the IMU frame.
 * @param imu_packets The vector to fill with the IMU packets.
 * @param available_count The number of available packets.
 * @return The result of the operation which indicates if the frame was successfully retrieved.
 */
TryGetResult try_get_imu_packets(dai::DataOutputQueue* queue, rust::Slice<cxxImuPacket> imu_packets, uint32_t& available_count) {
    std::shared_ptr<dai::IMUData> imu_data = nullptr;
    try {
        imu_data = queue->tryGet<dai::IMUData>();
    } catch (const std::exception& e) {
        return TryGetResult::QueueError;
    }

    if(!imu_data) {
        return TryGetResult::TryAgain;
    }

    // get the number of available packets and fill output buffer
    available_count = imu_data->packets.size();
    if(available_count > imu_packets.size()) {
        return TryGetResult::InvalidSize;
    }

    for(auto i = 0; i < available_count; i++) {
        auto& packet = imu_data->packets[i];
        imu_packets[i].accel.x = packet.acceleroMeter.x;
        imu_packets[i].accel.y = packet.acceleroMeter.y;
        imu_packets[i].accel.z = packet.acceleroMeter.z;
        imu_packets[i].gyro.x = packet.gyroscope.x;
        imu_packets[i].gyro.y = packet.gyroscope.y;
        imu_packets[i].gyro.z = packet.gyroscope.z;
        imu_packets[i].info.sequence_number = packet.gyroscope.getSequenceNum();
        imu_packets[i].info.timestamp = std::chrono::duration<double>(packet.gyroscope.getTimestamp().time_since_epoch()).count();
    }

    return TryGetResult::Ok;
}

/**
 * @brief Sets the camera settings on the given input queue.
 *
 * @param queue The input queue on which to set the camera settings.
 * @param settings The camera settings to request to set.
 */
void set_camera_settings(dai::DataInputQueue* queue, cxxCameraControlSettings const &settings) {
    dai::CameraControl control;
    if (settings.enable_auto_exposure) {
        control.setAutoExposureEnable();
    } else {
        control.setManualExposure(settings.exposure_time_us, settings.iso_sensitivity);
    }
    if (settings.enable_auto_focus) {
        control.setAutoFocusMode(dai::CameraControl::AutoFocusMode::CONTINUOUS_VIDEO);
    } else {
        control.setAutoFocusMode(dai::CameraControl::AutoFocusMode::OFF);
        control.setManualFocus(settings.lens_position);
    }
    if (settings.enable_auto_white_balance) {
        control.setAutoWhiteBalanceMode(
            dai::CameraControl::AutoWhiteBalanceMode::AUTO
        );
    } else {
        control.setAutoWhiteBalanceMode(
            dai::CameraControl::AutoWhiteBalanceMode::OFF
        );
        control.setManualWhiteBalance(settings.color_temperature_kelvins);
    }
    queue->send(control);
}

}  // namespace dai
