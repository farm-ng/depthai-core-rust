#include "depthai/utility/RecordReplay.hpp"

#include <spdlog/spdlog.h>

#include <filesystem>
#include <mcap/types.hpp>
#include <optional>
#include <stdexcept>

#include "Environment.hpp"
#include "RecordReplayImpl.hpp"
#include "build/version.hpp"
#include "depthai/utility/RecordReplaySchema.hpp"
#include "utility/Compression.hpp"
#include "utility/Platform.hpp"

namespace dai {
namespace utility {

ByteRecorder::~ByteRecorder() {
    close();
}

void ByteRecorder::init(const std::string& filePath, RecordConfig::CompressionLevel compressionLevel, RecordType recordingType) {
    if(initialized) {
        throw std::runtime_error("ByteRecorder already initialized");
    }
    if(filePath.empty()) {
        throw std::runtime_error("ByteRecorder file path is empty");
    }
    {
        auto options = mcap::McapWriterOptions("");
        options.library = "depthai" + std::string(build::VERSION);
        switch(compressionLevel) {
            case RecordConfig::CompressionLevel::NONE:
                options.compression = mcap::Compression::None;
                break;
            case RecordConfig::CompressionLevel::FASTEST:
                options.compressionLevel = mcap::CompressionLevel::Fastest;
                break;
            case RecordConfig::CompressionLevel::FAST:
                options.compressionLevel = mcap::CompressionLevel::Fast;
                break;
            case RecordConfig::CompressionLevel::DEFAULT:
                options.compressionLevel = mcap::CompressionLevel::Default;
                break;
            case RecordConfig::CompressionLevel::SLOW:
                options.compressionLevel = mcap::CompressionLevel::Slow;
                break;
            case RecordConfig::CompressionLevel::SLOWEST:
                options.compressionLevel = mcap::CompressionLevel::Slowest;
                break;
        }
        options.compression = mcap::Compression::Lz4;
        const auto res = writer.open(filePath, options);
        if(!res.ok()) {
            throw std::runtime_error("Failed to open file for writing: " + res.message);
        }
    }
    {
        const char* schemaText = DEFAULT_SHEMA;
        std::string channelName = "default";
        switch(recordingType) {
            case RecordType::Video:
                channelName = "video";
                schemaText = VIDEO_SHEMA;
                break;
            case RecordType::Imu:
                channelName = "imu";
                schemaText = IMU_SHEMA;
                break;
            case RecordType::Other:
                channelName = "default";
                schemaText = DEFAULT_SHEMA;
                break;
        }
        mcap::Schema schema(channelName, "jsonschema", schemaText);
        writer.addSchema(schema);
        mcap::Channel channel(channelName, "json", schema.id);
        writer.addChannel(channel);
        channelId = channel.id;
    }

    initialized = true;
}

void ByteRecorder::close() {
    if(initialized) {
        writer.close();
        initialized = false;
    }
}

BytePlayer::~BytePlayer() {
    close();
}

void BytePlayer::init(const std::string& filePath) {
    if(initialized) {
        throw std::runtime_error("BytePlayer already initialized");
    }
    if(filePath.empty()) {
        throw std::runtime_error("BytePlayer file path is empty");
    }
    {
        const auto res = reader.open(filePath);
        if(!res.ok()) {
            throw std::runtime_error("Failed to open file for reading: " + res.message);
        }
    }
    messageView = std::make_unique<mcap::LinearMessageView>(reader.readMessages());
    it = std::make_unique<mcap::LinearMessageView::Iterator>(messageView->begin());
    initialized = true;
}

std::optional<nlohmann::json> BytePlayer::next() {
    if(!initialized) {
        throw std::runtime_error("BytePlayer not initialized");
    }
    if(*it == messageView->end()) return std::nullopt;
    if((*it)->channel->messageEncoding != "json") {
        throw std::runtime_error("Unsupported message encoding: " + (*it)->channel->messageEncoding);
    }
    std::string_view asString(reinterpret_cast<const char*>((*it)->message.data), (*it)->message.dataSize);

    nlohmann::json j = nlohmann::json::parse(asString);

    ++(*it);

    return j;
}

void BytePlayer::restart() {
    if(!initialized) {
        throw std::runtime_error("BytePlayer not initialized");
    }
    it = std::make_unique<mcap::LinearMessageView::Iterator>(messageView->begin());
}

void BytePlayer::close() {
    if(initialized) {
        reader.close();
        initialized = false;
    }
}

std::optional<std::tuple<uint32_t, uint32_t>> BytePlayer::getVideoSize(const std::string& filePath) {
    if(filePath.empty()) {
        throw std::runtime_error("File path is empty in BytePlayer::getVideoSize");
    }
    mcap::McapReader reader;
    {
        const auto res = reader.open(filePath);
        if(!res.ok()) {
            throw std::runtime_error("Failed to open file for reading: " + res.message);
        }
    }
    auto messageView = reader.readMessages();
    if(messageView.begin() == messageView.end()) {
        return std::nullopt;
    } else {
        auto msg = messageView.begin();
        if(msg->channel->messageEncoding != "json") {
            throw std::runtime_error("Unsupported message encoding: " + msg->channel->messageEncoding);
        }
        std::string_view asString(reinterpret_cast<const char*>(msg->message.data), msg->message.dataSize);
        nlohmann::json j = nlohmann::json::parse(asString);

        auto type = j["type"].get<utility::RecordType>();
        if(type == utility::RecordType::Video) {
            auto width = j["width"].get<uint32_t>();
            auto height = j["height"].get<uint32_t>();
            return std::make_tuple(width, height);
        }
    }
    return std::nullopt;
}

bool checkRecordConfig(std::string& recordPath, RecordConfig& config) {
    if(!platform::checkPathExists(recordPath)) {
        if(!std::filesystem::create_directories(recordPath)) {
            spdlog::warn("DEPTHAI_RECORD path is invalid. Record disabled.");
            return false;
        }
        std::filesystem::permissions(recordPath, std::filesystem::perms::owner_write, std::filesystem::perm_options::add);
        config.outputDir = recordPath;
        return true;
    }
    if(platform::checkPathExists(recordPath, true)) {
        // Is a directory
        config.outputDir = recordPath;
    } else {
        // Is a file
        std::string ext = recordPath.substr(recordPath.find_last_of('.') + 1);
        if(ext != "json") {
            spdlog::warn("DEPTHAI_RECORD path is not a directory or a json file. Record disabled.");
            return false;
        }
        try {
            std::ifstream file(recordPath);
            json j = json::parse(file);
            config = j.get<RecordConfig>();

            if(platform::checkPathExists(config.outputDir, true)) {
                // Is a directory
                recordPath = config.outputDir;
            } else {
                bool ok = true;
                if(platform::checkPathExists(config.outputDir, false)) {
                    spdlog::warn("Record config path is a file");
                    ok = false;
                } else {
                    if(!std::filesystem::create_directories(config.outputDir)) {
                        spdlog::warn("Record config output directory is invalid");
                        ok = false;
                    }
                    std::filesystem::permissions(config.outputDir, std::filesystem::perms::owner_write, std::filesystem::perm_options::add);
                }
                return ok;
            }
        } catch(const std::exception& e) {
            spdlog::warn("Error while processing DEPTHAI_RECORD json file: {}. Record disabled.", e.what());
            return false;
        }
    }
    return true;
}

bool allMatch(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
    for(const auto& el : v1) {
        if(std::find(v2.begin(), v2.end(), el) == v2.end()) return false;
    }
    return true;
}
std::string matchTo(const std::vector<std::string>& mxIds, const std::vector<std::string>& filenames, const std::vector<std::string>& nodenames) {
    std::string mxId = "";
    for(const auto& id : mxIds) {
        std::vector<std::string> matches;
        for(const auto& filename : filenames) {
            if(filename.size() >= 4 && filename.substr(filename.size() - 4, filename.size()) != "meta" && filename.find(id) != std::string::npos) {
                matches.push_back(filename.substr(id.size() + 1, filename.find_last_of('.') - id.size() - 1));
            }
        }
        if(matches.size() == nodenames.size()) {
            if(allMatch(matches, nodenames)) {
                if(mxId.empty()) {
                    mxId = id;
                } else {
                    throw std::runtime_error("Multiple recordings match the pipeline configuration - unsupported.");
                }
            }
        }
    }
    return mxId;
}

}  // namespace utility
}  // namespace dai