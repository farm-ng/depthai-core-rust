#define _USE_MATH_DEFINES
#include "depthai/pipeline/datatype/ImgFrame.hpp"
#include "depthai/common/RotatedRect.hpp"
#include "depthai/common/ImgTransformations.hpp"
#include "depthai/utility/SharedMemory.hpp"
#include "spdlog/fmt/fmt.h"
#include "spdlog/spdlog.h"
namespace dai {

ImgFrame::ImgFrame() {
    // Set timestamp to now
    setTimestamp(std::chrono::steady_clock::now());
}

ImgFrame::ImgFrame(size_t size) : ImgFrame() {
    auto mem = std::make_shared<VectorMemory>();
    mem->resize(size);
    data = mem;
}

ImgFrame::ImgFrame(long fd) : ImgFrame() {
    auto mem = std::make_shared<SharedMemory>(fd);
    data = mem;
}

ImgFrame::ImgFrame(long fd, size_t size) : ImgFrame() {
    auto mem = std::make_shared<SharedMemory>(fd, size);
    data = mem;
}

std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> ImgFrame::getTimestamp(CameraExposureOffset offset) const {
    auto ts = getTimestamp();
    auto expTime = getExposureTime();
    switch(offset) {
        case CameraExposureOffset::START:
            return ts - expTime;
        case CameraExposureOffset::MIDDLE:
            return ts - expTime / 2;
        case CameraExposureOffset::END:
        default:
            return ts;
    }
}
std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> ImgFrame::getTimestampDevice(CameraExposureOffset offset) const {
    auto ts = getTimestampDevice();
    auto expTime = getExposureTime();
    switch(offset) {
        case CameraExposureOffset::START:
            return ts - expTime;
        case CameraExposureOffset::MIDDLE:
            return ts - expTime / 2;
        case CameraExposureOffset::END:
        default:
            return ts;
    }
}

unsigned int ImgFrame::getInstanceNum() const {
    return instanceNum;
}
unsigned int ImgFrame::getCategory() const {
    return category;
}
unsigned int ImgFrame::getWidth() const {
    return fb.width;
}

unsigned int ImgFrame::getStride() const {
    if(fb.stride == 0) {
        return static_cast<unsigned>(std::round(static_cast<float>(getWidth()) * getBytesPerPixel()));
    }
    return fb.stride;
}
unsigned int ImgFrame::getPlaneStride(int planeIndex) const {
    int planeStride = 0;
    switch(planeIndex) {
        case 0:
            planeStride = fb.p2Offset - fb.p1Offset;
            break;
        case 1:
            planeStride = fb.p3Offset - fb.p2Offset;
            break;
    }
    if(planeStride <= 0) planeStride = getStride() * getHeight();
    return planeStride;
}
unsigned int ImgFrame::getHeight() const {
    return fb.height;
}
unsigned int ImgFrame::getPlaneHeight() const {
    return getPlaneStride() / getStride();
}
ImgFrame::Type ImgFrame::getType() const {
    return fb.type;
}
float ImgFrame::getBytesPerPixel() const {
    return typeToBpp(getType());
}
std::chrono::microseconds ImgFrame::getExposureTime() const {
    return std::chrono::microseconds(cam.exposureTimeUs);
}
int ImgFrame::getSensitivity() const {
    return cam.sensitivityIso;
}
int ImgFrame::getColorTemperature() const {
    return cam.wbColorTemp;
}
int ImgFrame::getLensPosition() const {
    return cam.lensPosition;
}

unsigned int ImgFrame::getSourceWidth() const {
    return sourceFb.width;
}

float ImgFrame::getLensPositionRaw() const {
    return cam.lensPositionRaw;
}

unsigned int ImgFrame::getSourceHeight() const {
    return sourceFb.height;
}

ImgFrame& ImgFrame::setInstanceNum(unsigned int instanceNum) {
    this->instanceNum = instanceNum;
    return *this;
}
ImgFrame& ImgFrame::setCategory(unsigned int category) {
    this->category = category;
    return *this;
}

ImgFrame& ImgFrame::setWidth(unsigned int width) {
    fb.width = width;
    return *this;
}
ImgFrame& ImgFrame::setStride(unsigned int stride) {
    fb.stride = stride;
    return *this;
}
ImgFrame& ImgFrame::setHeight(unsigned int height) {
    fb.height = height;
    return *this;
}
ImgFrame& ImgFrame::setSize(unsigned int width, unsigned int height) {
    setWidth(width);
    setHeight(height);
    return *this;
}
ImgFrame& ImgFrame::setSize(std::tuple<unsigned int, unsigned int> size) {
    setSize(std::get<0>(size), std::get<1>(size));
    return *this;
}

ImgFrame& ImgFrame::setSourceSize(unsigned int width, unsigned int height) {
    sourceFb.width = width;
    sourceFb.stride = width;
    sourceFb.height = height;
    transformation = ImgTransformation(width, height);
    return *this;
}

ImgFrame& ImgFrame::setSourceSize(std::tuple<unsigned int, unsigned int> size) {
    setSourceSize(std::get<0>(size), std::get<1>(size));
    return *this;
}
ImgFrame& ImgFrame::setType(Type type) {
    fb.type = type;
    fb.bytesPP = ImgFrame::typeToBpp(fb.type);
    return *this;
}

ImgFrame& ImgFrame::setMetadata(const ImgFrame& sourceFrame) {
    auto tmpData = this->data;
    *this = sourceFrame;
    this->data = tmpData;  // Keep the original data
    return *this;
}

ImgFrame& ImgFrame::setMetadata(const std::shared_ptr<ImgFrame>& sourceFrame) {
    if(sourceFrame == nullptr) {
        throw std::invalid_argument("Source frame is null");
    }
    return setMetadata(*sourceFrame);
}

bool ImgFrame::validateTransformations() const {
    const auto [width, height] = transformation.getSize();
    const auto [srcWidth, srcHeight] = transformation.getSourceSize();
    return transformation.isValid() && width == getWidth() && height == getHeight() && srcWidth == getSourceWidth() && srcHeight == getSourceHeight();
}

Point2f ImgFrame::remapPointFromSource(const Point2f& point) const {
    if(point.isNormalized()) {
        throw std::runtime_error("Point must be denormalized");
    }
    if(!validateTransformations()) {
        throw std::runtime_error("ImgTransformation is not valid");
    }
    return transformation.transformPoint(point);
}

Point2f ImgFrame::remapPointToSource(const Point2f& point) const {
    if(point.isNormalized()) {
        throw std::runtime_error("Point must be denormalized");
    }
    if(!validateTransformations()) {
        throw std::runtime_error("ImgTransformation is not valid");
    }
    return transformation.invTransformPoint(point);
}

Rect ImgFrame::remapRectFromSource(const Rect& rect) const {
    bool isNormalized = rect.isNormalized();
    auto returnRect = rect;
    if(isNormalized) {
        returnRect = returnRect.denormalize(getSourceWidth(), getSourceHeight());
    }
    auto topLeftTransformed = remapPointFromSource(returnRect.topLeft());
    auto bottomRightTransformed = remapPointFromSource(returnRect.bottomRight());
    returnRect = Rect(topLeftTransformed, bottomRightTransformed);
    if(isNormalized) {
        returnRect = returnRect.normalize(getWidth(), getHeight());
    }
    return returnRect;
}

Rect ImgFrame::remapRectToSource(const Rect& rect) const {
    bool isNormalized = rect.isNormalized();
    auto returnRect = rect;
    if(isNormalized) {
        returnRect = returnRect.denormalize(getWidth(), getHeight());
    }
    auto topLeftTransformed = remapPointToSource(returnRect.topLeft());
    auto bottomRightTransformed = remapPointToSource(returnRect.bottomRight());

    returnRect = Rect(topLeftTransformed, bottomRightTransformed);
    if(isNormalized) {
        returnRect = returnRect.normalize(getSourceWidth(), getSourceHeight());
    }
    return returnRect;
}

ImgFrame& ImgFrame::setSourceHFov(float degrees) {
    HFovDegrees = degrees;
    return *this;
}

float ImgFrame::getSourceHFov() const {
    return HFovDegrees;
}

float ImgFrame::getSourceDFov() const {
    // TODO only works rectlinear lenses (rectified frames).
    // Calculate the vertical FOV from the source dimensions and the source DFov
    float sourceWidth = getSourceWidth();
    float sourceHeight = getSourceHeight();

    if(sourceHeight <= 0) {
        throw std::runtime_error(fmt::format("Source height is invalid. Height: {}", sourceHeight));
    }
    if(sourceWidth <= 0) {
        throw std::runtime_error(fmt::format("Source width is invalid. Width: {}", sourceWidth));
    }
    float HFovDegrees = getSourceHFov();

    // Calculate the diagonal ratio (DR)
    float dr = std::sqrt(std::pow(sourceWidth, 2) + std::pow(sourceHeight, 2));

    // Validate the horizontal FOV
    if(HFovDegrees <= 0 || HFovDegrees >= 180) {
        throw std::runtime_error(fmt::format("Horizontal FOV is invalid. Horizontal FOV: {}", HFovDegrees));
    }

    float HFovRadians = HFovDegrees * (static_cast<float>(M_PI) / 180.0f);

    // Calculate the tangent of half of the HFOV
    float tanHFovHalf = std::tan(HFovRadians / 2);

    // Calculate the tangent of half of the VFOV
    float tanDiagonalFovHalf = (dr / sourceWidth) * tanHFovHalf;

    // Calculate the VFOV in radians
    float diagonalFovRadians = 2 * std::atan(tanDiagonalFovHalf);

    // Convert VFOV to degrees
    float diagonalFovDegrees = diagonalFovRadians * (180.0f / static_cast<float>(M_PI));
    return diagonalFovDegrees;
}

float ImgFrame::getSourceVFov() const {
    // TODO only works rectlinear lenses (rectified frames).
    // Calculate the vertical FOV from the source dimensions and the source DFov
    float sourceWidth = getSourceWidth();
    float sourceHeight = getSourceHeight();

    if(sourceHeight <= 0) {
        throw std::runtime_error(fmt::format("Source height is invalid. Height: {}", sourceHeight));
    }
    if(sourceWidth <= 0) {
        throw std::runtime_error(fmt::format("Source width is invalid. Width: {}", sourceWidth));
    }
    float HFovDegrees = getSourceHFov();

    // Validate the horizontal FOV
    if(HFovDegrees <= 0 || HFovDegrees >= 180) {
        throw std::runtime_error(fmt::format("Horizontal FOV is invalid. Horizontal FOV: {}", HFovDegrees));
    }

    float HFovRadians = HFovDegrees * (static_cast<float>(M_PI) / 180.0f);

    // Calculate the tangent of half of the HFOV
    float tanHFovHalf = std::tan(HFovRadians / 2);

    // Calculate the tangent of half of the VFOV
    float tanVerticalFovHalf = (sourceHeight / sourceWidth) * tanHFovHalf;

    // Calculate the VFOV in radians
    float verticalFovRadians = 2 * std::atan(tanVerticalFovHalf);

    // Convert VFOV to degrees
    float verticalFovDegrees = verticalFovRadians * (180.0f / static_cast<float>(M_PI));
    return verticalFovDegrees;
}

Point2f ImgFrame::remapPointBetweenSourceFrames(const Point2f& point, const ImgFrame& sourceImage, const ImgFrame& destImage) {
    auto hFovDegreeDest = destImage.getSourceHFov();
    auto vFovDegreeDest = destImage.getSourceVFov();
    auto hFovDegreeOrigin = sourceImage.getSourceHFov();
    auto vFovDegreeOrigin = sourceImage.getSourceVFov();

    float hFovRadiansDest = (hFovDegreeDest * ((float)M_PI / 180.0f));
    float vFovRadiansDest = (vFovDegreeDest * ((float)M_PI / 180.0f));
    float hFovRadiansOrigin = (hFovDegreeOrigin * ((float)M_PI / 180.0f));
    float vFovRadiansOrigin = (vFovDegreeOrigin * ((float)M_PI / 180.0f));
    if(point.isNormalized()) {
        throw std::runtime_error("Point is normalized. Cannot remap normalized points");
    }

    if(sourceImage.getSourceWidth() == 0 || sourceImage.getSourceHeight() == 0 || destImage.getSourceWidth() == 0 || destImage.getSourceHeight() == 0) {
        throw std::runtime_error("Source image has invalid dimensions - all dimensions need to be set before remapping");
    }

    if(!(sourceImage.getSourceHFov() > 0.1f)) {
        throw std::runtime_error("Source image has invalid horizontal FOV - horizontal FOV needs to be set before remapping");
    }

    if(!(destImage.getSourceHFov() > 0.1f)) {
        throw std::runtime_error("Destination image has invalid horizontal FOV - horizontal FOV needs to be set before remapping");
    }

    // Calculate the factor between the FOVs
    // kX of 1.2 would mean that the destination image has 1.2 times wider FOV than the source image
    float kX = ((std::tan(hFovRadiansDest / 2) / std::tan(hFovRadiansOrigin / 2)));
    float kY = ((std::tan(vFovRadiansDest / 2) / std::tan(vFovRadiansOrigin / 2)));

    auto returnPoint = point;

    // Scale the point to the destination image
    returnPoint.x = std::round(point.x * (static_cast<float>(destImage.getSourceWidth()) / sourceImage.getSourceWidth()));
    returnPoint.y = std::round(point.y * (static_cast<float>(destImage.getSourceHeight()) / sourceImage.getSourceHeight()));

    // Adjust the point to the destination image
    unsigned adjustedWidth = std::round(destImage.getSourceWidth() * kX);
    unsigned adjustedHeight = std::round(destImage.getSourceHeight() * kY);

    int diffX = ((int)adjustedWidth - (int)destImage.getSourceWidth()) / 2;
    int diffY = ((int)adjustedHeight - (int)destImage.getSourceHeight()) / 2;

    int adjustedFrameX = returnPoint.x + diffX;
    int adjustedFrameY = returnPoint.y + diffY;

    // Scale the point back to the destination frame
    returnPoint = Point2f(std::round(adjustedFrameX / kX), std::round(adjustedFrameY / kY));
    returnPoint.x = std::max(0.0f, std::min(returnPoint.x, (float)destImage.getSourceWidth()));
    returnPoint.y = std::max(0.0f, std::min(returnPoint.y, (float)destImage.getSourceHeight()));

    return returnPoint;
}

Point2f ImgFrame::remapPointBetweenFrames(const Point2f& originPoint, const ImgFrame& originFrame, const ImgFrame& destFrame) {
    if(originFrame.getInstanceNum() == destFrame.getInstanceNum()) {
        if((originFrame.getSourceHeight() != destFrame.getSourceHeight()) || (originFrame.getSourceWidth() != destFrame.getSourceWidth())
           || (originFrame.getSourceHFov() != destFrame.getSourceHFov()) || (originFrame.getSourceVFov() != destFrame.getSourceVFov())) {
            throw std::runtime_error("Frames have the same instance numbers, but different source dimensions and/or FOVs.");
        }
    }
    return originFrame.transformation.remapPointTo(destFrame.transformation, originPoint);
}

Rect ImgFrame::remapRectBetweenFrames(const Rect& originRect, const ImgFrame& originFrame, const ImgFrame& destFrame) {
    if(originFrame.getInstanceNum() == destFrame.getInstanceNum()) {
        if((originFrame.getSourceHeight() != destFrame.getSourceHeight()) || (originFrame.getSourceWidth() != destFrame.getSourceWidth())
           || (originFrame.getSourceHFov() != destFrame.getSourceHFov()) || (originFrame.getSourceVFov() != destFrame.getSourceVFov())) {
            throw std::runtime_error("Frames have the same instance numbers, but different source dimensions and/or FOVs.");
        }
    }
    bool normalized = originRect.isNormalized();
    auto srcRect = originRect;
    srcRect = srcRect.denormalize(originFrame.getWidth(), originFrame.getHeight());
    dai::RotatedRect srcRRect;
    srcRRect.size = {srcRect.width, srcRect.height};
    srcRRect.center = {srcRect.x + srcRect.width / 2.f, srcRect.y + srcRect.height / 2.f};
    srcRRect.angle = 0.f;
    auto dstRRect = originFrame.transformation.remapRectTo(destFrame.transformation, srcRRect);
    auto [minx, miny, maxx, maxy] = dstRRect.getOuterRect();
    dai::Rect returnRect(minx, miny, maxx - minx, maxy - miny);
    if(normalized) {
        returnRect = returnRect.normalize(destFrame.getWidth(), destFrame.getHeight());
    }
    return returnRect;
}

}  // namespace dai
