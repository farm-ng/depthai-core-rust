#[cxx::bridge(namespace = "dai")]
pub mod ffi {

    #[derive(Debug)]
    #[repr(i32)]
    pub enum cxxOakCameraEncodingQuality {
        Baseline = 0,
        Main = 1,
        High = 2,
    }

    #[derive(Debug)]
    #[repr(i32)]
    pub enum cxxEncodingRateControlMode {
        Cbr = 0,
        Vbr = 1,
    }

    #[derive(Debug, Clone)]
    struct cxxPipelineOptions {
        oak_id: String,
        use_usb2: bool,
        enable_cam_left_mono: bool,
        enable_cam_right_mono: bool,
        enable_cam_color: bool,
        queue_capacity: u32,
        queue_blocking: bool,
        camera_mono_fps: f32,
        camera_color_fps: f32,
        encoding_bitrate_kbps: u32,
        encoding_quality: cxxOakCameraEncodingQuality,
        encoding_rate_control_mode: cxxEncodingRateControlMode,
        encoding_quality: u32,
        encoding_frames_per_keyframe: u32,
        imu_use_raw: bool,
        imu_report_rate_hz: u32,
        imu_batch_report_threshold: u32,
        imu_max_batch_reports: u32,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxImageFrameInfo {
        timestamp: f64,
        sequence_number: i64,
        iso_sensitivity: i64,
        exposure_time_us: i64,
        available_bytes: u32,
    }

    #[derive(Debug, Clone, Default)]
    struct cxxCameraControlSettings {
        enable_auto_exposure: bool,
        enable_auto_focus: bool,
        enable_auto_white_balance: bool,
        exposure_time_us: u32,
        iso_sensitivity: u32,
        lens_position: u8,
        color_temperature_kelvins: u16,
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
        QueueError = 3,
    }

    extern "C++" {
        include!("depthai/depthai.hpp");
        type Device;
        type Pipeline;
        type DataOutputQueue;
        type DataInputQueue;
    }

    // C++ types and signatures exposed to Rust.
    unsafe extern "C++" {
        include!("src/dai/cxx/dai_wrapper.h");

        fn get_all_available_devices() -> Vec<String>;

        fn open_device(oak_id: &str, usb2_mode: bool) -> *mut Device;

        fn make_pipeline_encoding(options: &cxxPipelineOptions) -> *mut Pipeline;

        unsafe fn start_pipeline(device: *mut Device, pipeline: *mut Pipeline) -> bool;

        unsafe fn get_output_queue(
            device: *mut Device,
            name: &str,
            max_capacity: u32,
            blocking: bool,
        ) -> *mut DataOutputQueue;

        unsafe fn get_input_queue(
            device: *mut Device,
            name: &str,
            max_capacity: u32,
            blocking: bool,
        ) -> *mut DataInputQueue;

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

        unsafe fn set_camera_settings(
            queue: *mut DataInputQueue,
            settings: &cxxCameraControlSettings,
        );
    }
}
