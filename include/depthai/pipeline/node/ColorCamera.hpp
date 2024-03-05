#pragma once

#include <depthai/pipeline/DeviceNode.hpp>
#include <depthai/pipeline/datatype/CameraControl.hpp>
#include <depthai/pipeline/datatype/ImgFrame.hpp>
// shared
#include <depthai/properties/ColorCameraProperties.hpp>

namespace dai {
namespace node {

/**
 * @brief ColorCamera node. For use with color sensors.
 */
class ColorCamera : public DeviceNodeCRTP<DeviceNode, ColorCamera, ColorCameraProperties> {
   public:
    constexpr static const char* NAME = "ColorCamera";
    using DeviceNodeCRTP::DeviceNodeCRTP;
    void build();

   protected:
    Properties& getProperties();
    bool isSourceNode() const override;
    NodeRecordParams getNodeRecordParams() const override;
    Output& getRecordOutput() override;
    Input& getReplayInput() override;

   public:
    /**
     * Constructs ColorCamera node.
     */
    ColorCamera() = default;
    ColorCamera(std::unique_ptr<Properties> props);

    /**
     * Computes the scaled size given numerator and denominator
     */
    int getScaledSize(int input, int num, int denom) const;

    /**
     * Initial control options to apply to sensor
     */
    CameraControl initialControl;

    /**
     * Input for ImageManipConfig message, which can modify crop parameters in runtime
     *
     * Default queue is non-blocking with size 8
     */
    Input inputConfig{true, *this, "inputConfig", Input::Type::SReceiver, false, 8, {{DatatypeEnum::ImageManipConfig, false}}};

    /**
     * Input for CameraControl message, which can modify camera parameters in runtime
     *
     * Default queue is blocking with size 8
     */
    Input inputControl{true, *this, "inputControl", Input::Type::SReceiver, true, 8, {{DatatypeEnum::CameraControl, false}}};

    /**
     * Input for mocking 'isp' functionality.
     *
     * Default queue is blocking with size 8
     */
    Input mockIsp{*this, "mockIsp", Input::Type::SReceiver, true, 8, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs ImgFrame message that carries NV12 encoded (YUV420, UV plane interleaved) frame data.
     *
     * Suitable for use with VideoEncoder node
     */
    Output video{true, *this, "video", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs ImgFrame message that carries BGR/RGB planar/interleaved encoded frame data.
     *
     * Suitable for use with NeuralNetwork node
     */
    Output preview{true, *this, "preview", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs ImgFrame message that carries NV12 encoded (YUV420, UV plane interleaved) frame data.
     *
     * The message is sent only when a CameraControl message arrives to inputControl with captureStill command set.
     */
    Output still{true, *this, "still", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs ImgFrame message that carries YUV420 planar (I420/IYUV) frame data.
     *
     * Generated by the ISP engine, and the source for the 'video', 'preview' and 'still' outputs
     */
    Output isp{true, *this, "isp", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs ImgFrame message that carries RAW10-packed (MIPI CSI-2 format) frame data.
     *
     * Captured directly from the camera sensor, and the source for the 'isp' output.
     */
    Output raw{true, *this, "raw", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Outputs metadata-only ImgFrame message as an early indicator of an incoming frame.
     *
     * It's sent on the MIPI SoF (start-of-frame) event, just after the exposure of the current frame
     * has finished and before the exposure for next frame starts.
     * Could be used to synchronize various processes with camera capture.
     * Fields populated: camera id, sequence number, timestamp
     */
    Output frameEvent{true, *this, "frameEvent", Output::Type::MSender, {{DatatypeEnum::ImgFrame, false}}};

    /**
     * Specify which board socket to use
     * @param boardSocket Board socket to use
     */
    void setBoardSocket(CameraBoardSocket boardSocket);

    /**
     * Retrieves which board socket to use
     * @returns Board socket to use
     */
    CameraBoardSocket getBoardSocket() const;

    /**
     * Specify which camera to use by name
     * @param name Name of the camera to use
     */
    void setCamera(std::string name);

    /**
     * Retrieves which camera to use by name
     * @returns Name of the camera to use
     */
    std::string getCamera() const;

    /// Set which color camera to use
    [[deprecated("Use 'setBoardSocket()' instead")]] void setCamId(int64_t id);

    /// Get which color camera to use
    [[deprecated("Use 'setBoardSocket()' instead")]] int64_t getCamId() const;

    /// Set camera image orientation
    void setImageOrientation(CameraImageOrientation imageOrientation);

    /// Get camera image orientation
    CameraImageOrientation getImageOrientation() const;

    /// Set color order of preview output images. RGB or BGR
    [[deprecated("Use 'setPreviewType()' instead")]] void setColorOrder(ColorCameraProperties::ColorOrder colorOrder);

    /// Get color order of preview output frames. RGB or BGR
    [[deprecated("Use 'getPreviewType()' instead")]] ColorCameraProperties::ColorOrder getColorOrder() const;

    /// Set planar or interleaved data of preview output frames
    [[deprecated("Use 'setPreviewType()' instead")]] void setInterleaved(bool interleaved);

    /// Get planar or interleaved data of preview output frames
    [[deprecated("Use 'getPreviewType()' instead")]] bool getInterleaved() const;

    /// Set type of preview output images.
    void setPreviewType(ImgFrame::Type type);

    /// Get the preview type
    ImgFrame::Type getPreviewType() const;

    /// Set fp16 (0..255) data type of preview output frames
    [[deprecated("Use 'setPreviewType()' instead")]] void setFp16(bool fp16);

    /// Get fp16 (0..255) data of preview output frames
    [[deprecated("Use 'getPreviewType()' instead")]] bool getFp16() const;

    /// Set preview output size
    void setPreviewSize(int width, int height);

    /// Set preview output size, as a tuple <width, height>
    void setPreviewSize(std::tuple<int, int> size);

    /// Set number of frames in preview pool
    void setPreviewNumFramesPool(int num);

    /// Set video output size
    void setVideoSize(int width, int height);

    /// Set video output size, as a tuple <width, height>
    void setVideoSize(std::tuple<int, int> size);

    /// Set number of frames in preview pool
    void setVideoNumFramesPool(int num);

    /// Set still output size
    void setStillSize(int width, int height);

    /// Set still output size, as a tuple <width, height>
    void setStillSize(std::tuple<int, int> size);

    /// Set number of frames in preview pool
    void setStillNumFramesPool(int num);

    /// Set sensor resolution
    void setResolution(Properties::SensorResolution resolution);

    /// Get sensor resolution
    Properties::SensorResolution getResolution() const;

    /// Set number of frames in raw pool
    void setRawNumFramesPool(int num);

    /// Set number of frames in isp pool
    void setIspNumFramesPool(int num);

    /// Set number of frames in all pools
    void setNumFramesPool(int raw, int isp, int preview, int video, int still);

    /**
     * Set 'isp' output scaling (numerator/denominator), preserving the aspect ratio.
     * The fraction numerator/denominator is simplified first to a irreducible form,
     * then a set of hardware scaler constraints applies:
     * max numerator = 16, max denominator = 63
     */
    void setIspScale(int numerator, int denominator);

    /// Set 'isp' output scaling, as a tuple <numerator, denominator>
    void setIspScale(std::tuple<int, int> scale);

    /**
     * Set 'isp' output scaling, per each direction. If the horizontal scaling factor
     * (horizNum/horizDen) is different than the vertical scaling factor
     * (vertNum/vertDen), a distorted (stretched or squished) image is generated
     */
    void setIspScale(int horizNum, int horizDenom, int vertNum, int vertDenom);

    /// Set 'isp' output scaling, per each direction, as <numerator, denominator> tuples
    void setIspScale(std::tuple<int, int> horizScale, std::tuple<int, int> vertScale);

    /**
     * Set rate at which camera should produce frames
     * @param fps Rate in frames per second
     */
    void setFps(float fps);

    // TODO(before mainline) - API not supported on RVC3
    /**
     * Isp 3A rate (auto focus, auto exposure, auto white balance, camera controls etc.).
     * Default (0) matches the camera FPS, meaning that 3A is running on each frame.
     * Reducing the rate of 3A reduces the CPU usage on CSS, but also increases the convergence rate of 3A.
     * Note that camera controls will be processed at this rate. E.g. if camera is running at 30 fps, and camera control is sent at every frame,
     * but 3A fps is set to 15, the camera control messages will be processed at 15 fps rate, which will lead to queueing.

     */
    void setIsp3aFps(int isp3aFps);

    // TODO(before mainline) - API not supported on RVC3
    // Set events on which frames will be received
    void setFrameEventFilter(const std::vector<dai::FrameEvent>& events);

    // Get events on which frames will be received
    std::vector<dai::FrameEvent> getFrameEventFilter() const;

    /**
     * Get rate at which camera should produce frames
     * @returns Rate in frames per second
     */
    float getFps() const;

    /// Get preview size as tuple
    std::tuple<int, int> getPreviewSize() const;
    /// Get preview width
    int getPreviewWidth() const;
    /// Get preview height
    int getPreviewHeight() const;

    /// Get video size as tuple
    std::tuple<int, int> getVideoSize() const;
    /// Get video width
    int getVideoWidth() const;
    /// Get video height
    int getVideoHeight() const;

    /// Get still size as tuple
    std::tuple<int, int> getStillSize() const;
    /// Get still width
    int getStillWidth() const;
    /// Get still height
    int getStillHeight() const;

    /// Get sensor resolution as size
    std::tuple<int, int> getResolutionSize() const;
    /// Get sensor resolution width
    int getResolutionWidth() const;
    /// Get sensor resolution height
    int getResolutionHeight() const;

    /// Get 'isp' output resolution as size, after scaling
    std::tuple<int, int> getIspSize() const;
    /// Get 'isp' output width
    int getIspWidth() const;
    /// Get 'isp' output height
    int getIspHeight() const;

    /**
     * Specify sensor center crop.
     * Resolution size / video size
     */
    void sensorCenterCrop();

    /**
     * Specifies the cropping that happens when converting ISP to video output. By default, video will be center cropped
     * from the ISP output. Note that this doesn't actually do on-sensor cropping (and MIPI-stream only that region), but
     * it does postprocessing on the ISP (on RVC).
     * @param x Top left X coordinate
     * @param y Top left Y coordinate
     */
    void setSensorCrop(float x, float y);

    /**
     * @returns Sensor top left crop coordinates
     */
    std::tuple<float, float> getSensorCrop() const;
    /// Get sensor top left x crop coordinate
    float getSensorCropX() const;
    /// Get sensor top left y crop coordinate
    float getSensorCropY() const;

    // Node properties configuration
    /**
     * Specify to wait until inputConfig receives a configuration message,
     * before sending out a frame.
     * @param wait True to wait for inputConfig message, false otherwise
     */
    [[deprecated("Use 'inputConfig.setWaitForMessage()' instead")]] void setWaitForConfigInput(bool wait);

    /**
     * @see setWaitForConfigInput
     * @returns True if wait for inputConfig message, false otherwise
     */
    [[deprecated("Use 'inputConfig.setWaitForMessage()' instead")]] bool getWaitForConfigInput() const;

    /**
     * Specifies whether preview output should preserve aspect ratio,
     * after downscaling from video size or not.
     *
     * @param keep If true, a larger crop region will be considered to still be able to
     * create the final image in the specified aspect ratio. Otherwise video size is resized to fit preview size
     */
    void setPreviewKeepAspectRatio(bool keep);

    /**
     * @see setPreviewKeepAspectRatio
     * @returns Preview keep aspect ratio option
     */
    bool getPreviewKeepAspectRatio();

    /// Get number of frames in preview pool
    int getPreviewNumFramesPool();
    /// Get number of frames in video pool
    int getVideoNumFramesPool();
    /// Get number of frames in still pool
    int getStillNumFramesPool();
    /// Get number of frames in raw pool
    int getRawNumFramesPool();
    /// Get number of frames in isp pool
    int getIspNumFramesPool();

    // TODO(before mainline) - API not supported on RVC2
    /// Set the source of the warp mesh or disable
    void setMeshSource(Properties::WarpMeshSource source);

    // TODO(before mainline) - API not supported on RVC2
    /// Gets the source of the warp mesh
    Properties::WarpMeshSource getMeshSource() const;

    /**
     * Specify local filesystem paths to the undistort mesh calibration files.
     *
     * When a mesh calibration is set, it overrides the camera intrinsics/extrinsics matrices.
     * Overrides useHomographyRectification behavior.
     * Mesh format: a sequence of (y,x) points as 'float' with coordinates from the input image
     * to be mapped in the output. The mesh can be subsampled, configured by `setMeshStep`.
     *
     * With a 1280x800 resolution and the default (16,16) step, the required mesh size is:
     *
     * width: 1280 / 16 + 1 = 81
     *
     * height: 800 / 16 + 1 = 51
     */
    // void loadMeshFile(const dai::Path& warpMesh);

    // TODO(before mainline) - API not supported on RVC2
    /**
     * Specify mesh calibration data for undistortion
     * See `loadMeshFiles` for the expected data format
     */
    void loadMeshData(const std::vector<std::uint8_t> warpMesh);

    // TODO(before mainline) - API not supported on RVC2
    /**
     * Set the distance between mesh points. Default: (32, 32)
     */
    void setMeshStep(int width, int height);

    // TODO(before mainline) - API not supported on RVC2
    /**
     * Set mesh size
     */
    void setMeshSize(int width, int height);

    // TODO(before mainline) - API not supported on RVC2
    /// Gets the distance between mesh points
    std::tuple<int, int> getMeshStep() const;

    // TODO(before mainline) - API not supported on RVC2
    /// Gets the mesh size
    std::tuple<int, int> getMeshSize() const;

    // TODO(before mainline) - API not supported on RVC2
    /// Set calibration alpha parameter that determines FOV of undistorted frames
    void setCalibrationAlpha(float alpha);

    // TODO(before mainline) - API not supported on RVC2
    /// Get calibration alpha parameter that determines FOV of undistorted frames
    float getCalibrationAlpha() const;
    // TODO(before mainline) - API not supported on RVC3
    /**
     * Configures whether the camera `raw` frames are saved as MIPI-packed to memory.
     * The packed format is more efficient, consuming less memory on device, and less data
     * to send to host: RAW10: 4 pixels saved on 5 bytes, RAW12: 2 pixels saved on 3 bytes.
     * When packing is disabled (`false`), data is saved lsb-aligned, e.g. a RAW10 pixel
     * will be stored as uint16, on bits 9..0: 0b0000'00pp'pppp'pppp.
     * Default is auto: enabled for standard color/monochrome cameras where ISP can work
     * with both packed/unpacked, but disabled for other cameras like ToF.
     */
    void setRawOutputPacked(bool packed);
};

}  // namespace node
}  // namespace dai
