#include "depthai/pipeline/datatype/PointCloudConfig.hpp"

namespace dai {

PointCloudConfig::Serialized PointCloudConfig::serialize() const {
    return {data, raw};
}

PointCloudConfig::PointCloudConfig() : Buffer(std::make_shared<RawPointCloudConfig>()), cfg(*dynamic_cast<RawPointCloudConfig*>(raw.get())) {}
PointCloudConfig::PointCloudConfig(std::shared_ptr<RawPointCloudConfig> ptr) : Buffer(std::move(ptr)), cfg(*dynamic_cast<RawPointCloudConfig*>(raw.get())) {}

dai::RawPointCloudConfig PointCloudConfig::get() const {
    return cfg;
}

PointCloudConfig& PointCloudConfig::set(dai::RawPointCloudConfig config) {
    cfg = config;
    return *this;
}

}  // namespace dai
