fn main() -> Result<(), Box<dyn std::error::Error>> {
    use cmake::Config;

    // get the current directory
    let current_dir = std::env::current_dir().unwrap();

    // Build the depthai-core library
    let dst = Config::new("..") // the main library is in the root of the repository
        .define(
            "DEPTHAI_SHARED_LOCAL",
            current_dir
                .join("../shared/depthai-shared")
                .display()
                .to_string(),
        )
        .define(
            "DEPTHAI_BOOTLOADER_SHARED_LOCAL",
            current_dir
                .join("../shared/depthai-bootloader-shared")
                .display()
                .to_string(),
        )
        .define("DEPTHAI_OPENCV_SUPPORT", "OFF")
        .define("CMAKE_WARN_DEPRECATED", "FALSE")
        .define("CMAKE_BUILD_TYPE", "Release")
        .build_arg("-Wno-dev")
        .build();
    let dst = dst.to_str().unwrap();

    // Compile the Rust-C++ bridge and bootloader code
    // Influenced by github.com:npenkov/depthai-rgb-encoding-example-rs.git
    cxx_build::bridges(["src/dai/cxx.rs"])
        .file("src/dai/cxx/dai_wrapper.cc")
        .includes(&[
            ".",
            &(dst.to_owned() + "/include"),
            &(dst.to_owned() + "/include/depthai"),
            &(dst.to_owned() + "/include/depthai-shared/3rdparty"),
            &(dst.to_owned() + "/lib/cmake/depthai/dependencies/include"),
        ])
        .flag_if_supported("-std=c++14")
        .flag_if_supported("-std=c++17")
        // this is needed to avoid warnings from the depthai library
        .flag("-Wno-extra")
        .compile("depthai-rust");

    // Debug info during the build
    println!("cargo:rerun-if-changed=src/dai/cxx.rs");
    println!("cargo:rerun-if-changed=src/dai/cxx/dai_wrapper.cc");
    println!("cargo:rerun-if-changed=src/dai/cxx/dai_wrapper.h");

    println!("cargo:rustc-link-search=native={}/lib", dst);
    println!(
        "cargo:rustc-link-search=native={}/lib/cmake/depthai/dependencies/lib",
        dst
    );
    println!("cargo:rustc-link-lib=static=depthai-core");
    println!("cargo:rustc-link-lib=static=depthai-resources");
    println!("cargo:rustc-link-lib=static=archive_static");
    println!("cargo:rustc-link-lib=static=bz2");
    println!("cargo:rustc-link-lib=static=lzma");
    println!("cargo:rustc-link-lib=static=spdlog");
    println!("cargo:rustc-link-lib=static=XLink");
    println!("cargo:rustc-link-lib=static=z");
    println!("cargo:rustc-link-lib=dylib=usb-1.0");

    Ok(())
}