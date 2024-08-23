#include <catch2/catch_all.hpp>

// std
#include <atomic>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>

// Include depthai library
#include <depthai/depthai.hpp>

#include "depthai/common/UsbSpeed.hpp"
#include "depthai/depthai.hpp"

TEST_CASE("Usb modes") {
    using namespace std;
    using namespace std::chrono;
    using namespace std::chrono_literals;

    std::shared_ptr<dai::Device> device;
    SECTION("UsbSpeed::HIGH") {
        device.reset(new dai::Device(dai::DeviceInfo(), dai::UsbSpeed::HIGH));
    }

    SECTION("UsbSpeed::SUPER") {
        device.reset(new dai::Device(dai::DeviceInfo(), dai::UsbSpeed::SUPER));
    }

    dai::Pipeline p(device);
    auto infoNode = p.create<dai::node::SystemLogger>();
    auto outputQueue = infoNode->out.createOutputQueue();
    p.start();

    const auto timeout = 1s;
    bool timeoutOccurred = false;
    auto infoFrame = outputQueue->get<dai::SystemInformation>(timeout, timeoutOccurred);

    REQUIRE(!timeoutOccurred);
    REQUIRE(infoFrame != nullptr);
    REQUIRE(infoFrame->leonCssCpuUsage.average >= 0.0f);
    REQUIRE(infoFrame->leonCssCpuUsage.average <= 1.0f);
}

TEST_CASE("Usb config modes") {
    using namespace std;
    using namespace std::chrono;
    using namespace std::chrono_literals;

    std::shared_ptr<dai::Device> device;

    dai::UsbSpeed speed;
    SECTION("UsbSpeed::HIGH") {
        speed = dai::UsbSpeed::HIGH;
    }

    SECTION("UsbSpeed::SUPER") {
        speed = dai::UsbSpeed::SUPER;
    }

    dai::Pipeline p(false);
    device.reset(new dai::Device(p, speed));

    REQUIRE(static_cast<uint32_t>(device->getUsbSpeed()) <= static_cast<uint32_t>(speed));
}
