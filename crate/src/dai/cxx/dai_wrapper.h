// Copyright (c) farm-ng, inc. All rights reserved.

#pragma once
#include "depthai/depthai.hpp"
#include "rust/cxx.h"

#include <memory>

namespace dai
{
    struct cxxPipelineOptions;
    struct cxxImageFrameInfo;
    struct cxxImuPacket;
    struct cxxImuPacketInfo;
    struct cxxCameraControlSettings;
    enum class TryGetResult;
    enum class cxxOakCameraEncodingQuality;

    rust::Vec<rust::String> get_all_available_devices();

    dai::Device *open_device(rust::Str const oak_id, bool usb2_mode);

    dai::Pipeline *make_pipeline_encoding(cxxPipelineOptions const &options);

    bool start_pipeline(dai::Device *device, dai::Pipeline *pipeline);

    dai::DataOutputQueue *get_output_queue(
        dai::Device *device, rust::Str const name,
        uint32_t max_capacity, bool blocking);

    dai::DataInputQueue *get_input_queue(
        dai::Device *device, rust::Str const name,
        uint32_t max_capacity, bool blocking);

    TryGetResult try_get_image_frame(
        dai::DataOutputQueue *queue,
        rust::Slice<uint8_t> dst_data,
        cxxImageFrameInfo &frame_info);

    TryGetResult try_get_imu_packets(
        dai::DataOutputQueue *queue,
        rust::Slice<cxxImuPacket> imu_packets,
        uint32_t &available_count);

    void set_camera_settings(
        dai::DataInputQueue *queue,
        cxxCameraControlSettings const &settings);

} // namespace dai
