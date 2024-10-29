use crate::dai;

/// State of the depthai device and pipeline
///
/// This struct is not thread safe, and should only be accessed from the main thread.
///
/// We need to keep the device and pipeline alive for the entire lifetime of the OakCamera instance.
pub struct DepthAiState {
    #[allow(dead_code)]
    device: *mut dai::Device,
    #[allow(dead_code)]
    pipeline: *mut dai::Pipeline,
    pub(crate) pipeline_options: dai::cxxPipelineOptions,
    left_camera_queue: *mut dai::DataOutputQueue,
    imu_queue: *mut dai::DataOutputQueue,
}

unsafe impl Send for DepthAiState {}
unsafe impl Sync for DepthAiState {}

impl DepthAiState {
    pub fn from_config(pipeline_options: &dai::cxxPipelineOptions) -> Result<Self, eyre::Error> {
        // make sure there is at least one device available
        let all_devices = dai::get_all_available_devices();
        log::debug!("Devices: {:?}", all_devices);

        //let first_device = match all_devices.first() {
        //    Some(device) => device,
        //    None => {
        //        return Err(eyre::eyre!("No devices found"));
        //    }
        //};

        log::info!("Using oak device mxid: {}", pipeline_options.mxid);

        // open the device and start the pipeline
        let device = dai::open_device(&pipeline_options.mxid, pipeline_options.use_usb2);
        if device.is_null() {
            return Err(eyre::eyre!(
                "Failed to open device {}",
                pipeline_options.mxid
            ));
        }

        // start the pipeline
        let pipeline = dai::make_pipeline_autonomy(pipeline_options);
        unsafe {
            if !dai::start_pipeline(device, pipeline) {
                return Err(eyre::eyre!("Failed to start pipeline"));
            }
        }

        // get the output queue to read the images from
        let left_camera_queue = unsafe {
            dai::get_output_queue(
                device,
                "cam_left",
                pipeline_options.queue_capacity,
                pipeline_options.queue_blocking,
            )
        };
        let imu_queue = unsafe {
            dai::get_output_queue(
                device,
                "imu",
                pipeline_options.queue_capacity,
                pipeline_options.queue_blocking,
            )
        };

        Ok(Self {
            device,
            pipeline,
            pipeline_options: pipeline_options.clone(),
            left_camera_queue,
            imu_queue,
        })
    }

    /// Tries to get an image frame from the left camera queue
    pub fn try_get_image(
        &self,
        image_data_buf: &mut [u8],
    ) -> Result<dai::cxxImageFrameInfo, eyre::Error> {
        let mut frame_info = dai::cxxImageFrameInfo::default();
        match unsafe {
            dai::try_get_image_frame(self.left_camera_queue, image_data_buf, &mut frame_info)
        } {
            dai::TryGetResult::Ok => Ok(frame_info),
            dai::TryGetResult::TryAgain => Err(eyre::eyre!("No image frame found, trying again")),
            dai::TryGetResult::InvalidSize => {
                Err(eyre::eyre!("Invalid image frame size, trying again"))
            }
            _ => Err(eyre::eyre!("Unexpected result from try_get_image_frame")),
        }
    }

    /// Tries to get an IMU packet from the IMU queue
    pub fn try_get_imu_packets(
        &self,
        imu_packets_buf: &mut [dai::cxxImuPacket],
    ) -> Result<u32, eyre::Error> {
        // get the IMU packets from the queue and fill the buffer
        let mut available_count = 0;
        match unsafe {
            dai::try_get_imu_packets(self.imu_queue, imu_packets_buf, &mut available_count)
        } {
            dai::TryGetResult::Ok => Ok(available_count),
            dai::TryGetResult::InvalidSize => {
                Err(eyre::eyre!("Invalid IMU packet size, trying again"))
            }
            dai::TryGetResult::TryAgain => Err(eyre::eyre!("No IMU packet found, trying again")),
            _ => Err(eyre::eyre!("Unexpected result from try_get_imu_packet")),
        }
    }
}
