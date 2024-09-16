#pragma once

#include <depthai/pipeline/DeviceNode.hpp>

// standard
#include <fstream>

// shared
#include <depthai/properties/EdgeDetectorProperties.hpp>

#include "depthai/pipeline/datatype/EdgeDetectorConfig.hpp"

namespace dai {
namespace node {

/**
 * @brief EdgeDetector node. Performs edge detection using 3x3 Sobel filter
 */
class EdgeDetector : public DeviceNodeCRTP<DeviceNode, EdgeDetector, EdgeDetectorProperties> {
   public:
    constexpr static const char* NAME = "EdgeDetector";
    using DeviceNodeCRTP::DeviceNodeCRTP;

   protected:
    Properties& getProperties();

   public:
    EdgeDetector() = default;
    EdgeDetector(std::unique_ptr<Properties> props);

    /**
     * Initial config to use for edge detection.
     */
    EdgeDetectorConfig initialConfig;

    /**
     * Input EdgeDetectorConfig message with ability to modify parameters in runtime.
     * Default queue is non-blocking with size 4.
     */
    Input inputConfig{*this, {"inputConfig", DEFAULT_GROUP, false, 4, {{{DatatypeEnum::EdgeDetectorConfig, false}}}, DEFAULT_WAIT_FOR_MESSAGE}};

    /**
     * Input image on which edge detection is performed.
     * Default queue is non-blocking with size 4.
     */
    Input inputImage{*this, {"inputImage", DEFAULT_GROUP, false, 4, {{{DatatypeEnum::ImgFrame, false}}}, true}};

    /**
     * Outputs image frame with detected edges
     */
    Output outputImage{*this, {"outputImage", DEFAULT_GROUP, {{{DatatypeEnum::ImgFrame, false}}}}};

    /**
     * Passthrough message on which the calculation was performed.
     */
    Output passthroughInputImage{*this, {"passthroughInputImage", DEFAULT_GROUP, {{{DatatypeEnum::ImgFrame, false}}}}};

    // Functions to set properties
    /**
     * Specify whether or not wait until configuration message arrives to inputConfig Input.
     * @param wait True to wait for configuration message, false otherwise.
     */
    [[deprecated("Use 'inputConfig.setWaitForMessage()' instead")]] void setWaitForConfigInput(bool wait);

    /**
     * @see setWaitForConfigInput
     * @returns True if wait for inputConfig message, false otherwise
     */
    [[deprecated("Use 'inputConfig.setWaitForMessage()' instead")]] bool getWaitForConfigInput() const;

    /**
     * Specify number of frames in pool.
     * @param numFramesPool How many frames should the pool have
     */
    void setNumFramesPool(int numFramesPool);

    /**
     * Specify maximum size of output image.
     * @param maxFrameSize Maximum frame size in bytes
     */
    void setMaxOutputFrameSize(int maxFrameSize);
};

}  // namespace node
}  // namespace dai
