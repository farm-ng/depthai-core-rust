#[cxx::bridge(namespace = "dai")]
pub mod ffi {

    #[derive(Debug, Clone)]
    struct cxxShape2 {
        rows: usize,
        cols: usize,
    }

    #[derive(Debug, Clone)]
    struct cxxPipelineOptions {
        oak_id: String,
        use_usb2: bool,
        camera_shape: cxxShape2,
        queue_capacity: u32,
        queue_blocking: bool,
        camera_fps: f32,
        imu_report_rate_hz: u32,
        imu_batch_report_threshold: u32,
        imu_max_batch_reports: u32,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxImageFrameInfo {
        timestamp: f64,
        sequence_number: i64,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxDVec3 {
        x: f64,
        y: f64,
        z: f64,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxImuPacketInfo {
        timestamp: f64,
        sequence_number: i32,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxImuPacket {
        accel: cxxDVec3,
        gyro: cxxDVec3,
        info: cxxImuPacketInfo,
    }

    #[derive(Debug)]
    #[repr(i32)]
    enum TryGetResult {
        InvalidSize = 0,
        Ok = 1,
        TryAgain = 2,
    }

    extern "C++" {
        include!("depthai/depthai.hpp");
        type Device;
        type Pipeline;
        type DataOutputQueue;
    }

    // C++ types and signatures exposed to Rust.
    unsafe extern "C++" {
        include!("src/dai/cxx/dai_wrapper.h");

        fn get_all_available_devices() -> Vec<String>;

        fn open_device(oak_id: &str, usb2_mode: bool) -> *mut Device;

        fn make_pipeline_autonomy(options: &cxxPipelineOptions) -> *mut Pipeline;

        unsafe fn start_pipeline(device: *mut Device, pipeline: *mut Pipeline) -> bool;

        unsafe fn get_output_queue(
            device: *mut Device,
            name: &str,
            max_capacity: u32,
            blocking: bool,
        ) -> *mut DataOutputQueue;

        unsafe fn try_get_image_frame(
            queue: *mut DataOutputQueue,
            dst_data: &mut [u8],
            frame_info: &mut cxxImageFrameInfo,
        ) -> TryGetResult;

        unsafe fn try_get_imu_packets(
            queue: *mut DataOutputQueue,
            imu_packets: &mut [cxxImuPacket],
            available_count: &mut u32,
        ) -> TryGetResult;
    }
}
