#include "src/dai/cxx/dai_wrapper.h"
#include "luxonis_oak_camera/src/dai/cxx.rs.h"

namespace dai
{

  /**
   * @brief Retrieves a list of all available devices.
   *
   * This function queries all connected devices and returns their identifiers.
   * If a device has a non-empty `mxid`, it is preferred and added to the list.
   * Otherwise, the device's name, which could be an IP or USB port name, is used.
   *
   * @return A vector of strings containing the identifiers of all available devices.
   */
  rust::Vec<rust::String> get_all_available_devices()
  {
    rust::Vec<rust::String> devices;
    for (auto &info : dai::XLinkConnection::getAllConnectedDevices(
             XLinkDeviceState_t::X_LINK_ANY_STATE, false))
    {
      if (!info.mxid.empty())
      {
        // prefer maxid if available
        devices.push_back(info.mxid);
      }
      else
      {
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
  dai::Device *open_device(
      rust::Str const oak_id, bool usb2_mode)
  {
    // Can accept mxid, ip address or usb port name
    DeviceInfo info = DeviceInfo(std::string(oak_id));
    auto usb_speed = !usb2_mode ? dai::UsbSpeed::SUPER_PLUS : dai::UsbSpeed::HIGH;
    auto device = new dai::Device(
        dai::OpenVINO::Version::VERSION_2022_1, info, usb_speed);
    // device->setLogLevel(dai::LogLevel::DEBUG);
    // device->setLogOutputLevel(dai::LogLevel::DEBUG);
    return device;
  }

  /**
   * @brief Creates a pipeline for autonomy with a camera and IMU.
   *
   * This function sets up a pipeline that includes a mono camera and an IMU sensor.
   * The camera is configured to use the left board socket and outputs at 800p resolution
   * with a frame rate of 30 FPS. The IMU is configured to report accelerometer and gyroscope
   * data at a rate of 100 Hz.
   *
   * @param options Configuration options for the pipeline (currently not used).
   * @return A pointer to the configured pipeline.
   */
  dai::Pipeline *make_pipeline_autonomy(cxxPipelineOptions const &options)
  {
    auto pipeline = new dai::Pipeline();

    // add the left camera to the pipeline
    std::shared_ptr<dai::node::MonoCamera> cam_left =
        pipeline->create<dai::node::MonoCamera>();

    // TODO: make these configurable through options
    cam_left->setBoardSocket(dai::CameraBoardSocket::CAM_B); // this should be the left camera
    cam_left->setResolution(dai::MonoCameraProperties::SensorResolution::THE_800_P);
    cam_left->setFps(options.camera_fps);

    auto xout_left = pipeline->create<dai::node::XLinkOut>();
    xout_left->setStreamName("cam_left");

    cam_left->out.link(xout_left->input);

    // assign the imu to the pipeline
    std::shared_ptr<dai::node::IMU> imu = pipeline->create<dai::node::IMU>();
    imu->enableIMUSensor(
        {dai::IMUSensor::ACCELEROMETER_RAW, dai::IMUSensor::GYROSCOPE_RAW},
        options.imu_report_rate_hz);
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
  bool start_pipeline(dai::Device *device, dai::Pipeline *pipeline)
  {
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
  dai::DataOutputQueue *get_output_queue(
      dai::Device *device,
      rust::Str const name,
      uint32_t max_capacity,
      bool blocking)
  {
    return device->getOutputQueue(std::string(name), max_capacity, blocking).get();
  }

  /**
   * @brief Tries to get an image frame from the given output queue.
   *
   * If no frame is available, a null pointer is returned to skip the tick in the codelet.
   *
   * @param queue The output queue from which to get the image frame.
   * @return The result of the operation which indicates if the frame was successfully retrieved.
   */
  TryGetResult try_get_image_frame(
      dai::DataOutputQueue *queue,
      rust::Slice<uint8_t> dst_data,
      cxxImageFrameInfo &frame_info)
  {
    auto img_frame = queue->tryGet<dai::ImgFrame>();
    if (!img_frame)
    {
      // no frame found, so we return a null pointer to skip the tick in the codelet
      return TryGetResult::TryAgain;
    }

    auto &data_vec = img_frame->getData();
    if (data_vec.size() != dst_data.size())
    {
      return TryGetResult::InvalidSize;
    }

    // give ownership of the data to the destination vector
    std::move(data_vec.begin(), data_vec.end(), dst_data.begin());

    // get the timestamp and sequence number to set in the message
    frame_info.timestamp = std::chrono::duration<double>(
                               img_frame->getTimestamp().time_since_epoch())
                               .count();
    frame_info.sequence_number = img_frame->getSequenceNum();

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
  TryGetResult try_get_imu_packets(
      dai::DataOutputQueue *queue,
      rust::Slice<cxxImuPacket> imu_packets,
      uint32_t &available_count)
  {
    auto imu_data = queue->tryGet<dai::IMUData>();
    if (!imu_data)
    {
      return TryGetResult::TryAgain;
    }

    // get the number of available packets and fill output buffer
    available_count = imu_data->packets.size();
    if (available_count > imu_packets.size())
    {
      return TryGetResult::InvalidSize;
    }

    for (auto i = 0; i < available_count; i++)
    {
      auto &packet = imu_data->packets[i];
      imu_packets[i].accel.x = packet.acceleroMeter.x;
      imu_packets[i].accel.y = packet.acceleroMeter.y;
      imu_packets[i].accel.z = packet.acceleroMeter.z;
      imu_packets[i].gyro.x = packet.gyroscope.x;
      imu_packets[i].gyro.y = packet.gyroscope.y;
      imu_packets[i].gyro.z = packet.gyroscope.z;
      imu_packets[i].info.sequence_number = packet.gyroscope.getSequenceNum();
      imu_packets[i].info.timestamp = std::chrono::duration<double>(
                                          packet.gyroscope.getTimestamp().time_since_epoch())
                                          .count();
    }

    return TryGetResult::Ok;
  }

} // namespace dai
