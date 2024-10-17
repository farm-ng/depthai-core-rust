#include "depthai/utility/EventsManager.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <utility>

#include "Environment.hpp"
#include "Logging.hpp"
#include "depthai/schemas/Event.pb.h"
#ifdef DEPTHAI_ENABLE_CURL
    #include <cpr/cpr.h>
namespace dai {

namespace utility {
using std::move;

EventData::EventData(const std::string& data, const std::string& fileName, const std::string& mimeType)
    : fileName(fileName), mimeType(mimeType), data(data), type(EventDataType::DATA) {}

EventData::EventData(std::string fileUrl) : data(std::move(fileUrl)), type(EventDataType::FILE_URL) {
    fileName = std::filesystem::path(data).filename().string();
    static std::map<std::string, std::string> mimeTypes = {{".html", "text/html"},
                                                           {".htm", "text/html"},
                                                           {".css", "text/css"},
                                                           {".js", "application/javascript"},
                                                           {".png", "image/png"},
                                                           {".jpg", "image/jpeg"},
                                                           {".jpeg", "image/jpeg"},
                                                           {".gif", "image/gif"},
                                                           {".svg", "image/svg+xml"},
                                                           {".json", "application/json"},
                                                           {".txt", "text/plain"}};
    auto ext = std::filesystem::path(data).extension().string();
    auto it = mimeTypes.find(ext);
    mimeType = "application/octet-stream";
    if(it != mimeTypes.end()) {
        mimeType = it->second;
    }
}

EventData::EventData(const std::shared_ptr<ImgFrame>& imgFrame, std::string fileName)
    : fileName(std::move(fileName)), mimeType("image/jpeg"), type(EventDataType::IMG_FRAME) {
    // Convert ImgFrame to bytes
    cv::Mat cvFrame = imgFrame->getCvFrame();
    std::vector<uchar> buf;
    cv::imencode(".jpg", cvFrame, buf);
    std::stringstream ss;
    ss.write((const char*)buf.data(), buf.size());
    data = ss.str();
}

EventData::EventData(const std::shared_ptr<EncodedFrame>& encodedFrame, std::string fileName)
    : fileName(std::move(fileName)), type(EventDataType::ENCODED_FRAME) {
    // Convert EncodedFrame to bytes
    if(encodedFrame->getProfile() != EncodedFrame::Profile::JPEG) {
        logger::error("Only JPEG encoded frames are supported");
        return;
    }
    std::stringstream ss;
    ss.write((const char*)encodedFrame->getData().data(), encodedFrame->getData().size());
    data = ss.str();
    mimeType = "image/jpeg";
}

EventData::EventData(const std::shared_ptr<NNData>& nnData, std::string fileName)
    : fileName(std::move(fileName)), mimeType("application/octet-stream"), type(EventDataType::NN_DATA) {
    // Convert NNData to bytes
    std::stringstream ss;
    ss.write((const char*)nnData->data->getData().data(), nnData->data->getData().size());
    data = ss.str();
}

bool EventData::toFile(const std::string& path) {
    // check if filename is not empty
    if(fileName.empty()) {
        logger::error("Filename is empty");
        return false;
    }
    std::filesystem::path p(path);
    if(type == EventDataType::FILE_URL) {
        // get the filename from the url
        std::filesystem::copy(data, p / fileName);
    } else {
        std::string extension = mimeType == "image/jpeg" ? ".jpg" : ".txt";
        // check if file exists, if yes, append a number to the filename
        std::string fileNameTmp = fileName;
        int i = 0;
        while(std::filesystem::exists(p / (fileNameTmp + extension))) {
            logger::warn("File {} already exists, appending number to filename", fileNameTmp);
            fileNameTmp = fileName + "_" + std::to_string(i);
            i++;
        }
        std::ofstream fileStream(p / (fileNameTmp + extension), std::ios::binary);
        fileStream.write(data.data(), data.size());
    }
    return true;
}
EventsManager::EventsManager(std::string url, bool uploadCachedOnStart, float publishInterval)
    : url(move(url)),
      queueSize(10),
      publishInterval(publishInterval),
      logResponse(false),
      verifySsl(false),
      connected(false),
      cacheDir("/internal/private"),
      uploadCachedOnStart(uploadCachedOnStart),
      cacheIfCannotSend(false) {
    sourceAppId = utility::getEnv("AGENT_APP_ID");
    sourceAppIdentifier = utility::getEnv("AGENT_APP_IDENTIFIER");
    token = utility::getEnv("DEPTHAI_HUB_API_KEY");
    eventBufferThread = std::thread([this]() {
        while(true) {
            sendEventBuffer();
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(this->publishInterval * 1000)));
        }
    });
    checkConnection();
    if(uploadCachedOnStart) {
        uploadCachedData();
    }
}

void EventsManager::sendEventBuffer() {
    std::lock_guard<std::mutex> lock(eventBufferMutex);
    if(eventBuffer.empty()) {
        return;
    }
    if(!checkConnection()) {
        if(cacheIfCannotSend) {
            cacheEvents();
        }
        return;
    }
    // Create request
    cpr::Url url = static_cast<cpr::Url>(this->url + "/v1/events");
    auto batchEvent = std::make_unique<proto::event::BatchUploadEvents>();
    for(auto& eventM : eventBuffer) {
        auto& event = eventM->event;
        batchEvent->add_events()->Swap(event.get());
    }
    std::string serializedEvent;
    batchEvent->SerializeToString(&serializedEvent);
    cpr::Response r = cpr::Post(url, cpr::Header{{"Authorization", "Bearer " + token}}, cpr::Body(serializedEvent), cpr::VerifySsl(verifySsl));
    if(r.status_code != cpr::status::HTTP_OK) {
        logger::error("Failed to send event: {} {}", r.text, r.status_code);
    } else {
        logger::info("Event sent successfully");
        if(logResponse) {
            logger::info("Response: {}", r.text);
        }
        // upload files
        auto batchUploadEventResult = std::make_unique<proto::event::BatchUploadEventsResult>();
        batchUploadEventResult->ParseFromString(r.text);
        for(int i = 0; i < batchUploadEventResult->events_size(); i++) {
            auto eventResult = batchUploadEventResult->events(i);
            if(eventResult.accepted().file_upload_urls_size() > 0) {
                for(int j = 0; j < eventResult.accepted().file_upload_urls().size(); j++) {
                    cpr::Url fileUrl = static_cast<cpr::Url>(this->url + eventResult.accepted().file_upload_urls(j));

                    sendFile(eventBuffer[i]->data[j], fileUrl);
                }
            }
        }
        for(auto& eventM : eventBuffer) {
            if(!eventM->cachePath.empty() && std::filesystem::exists(eventM->cachePath)) {
                std::filesystem::remove_all(eventM->cachePath);
            }
        }
        eventBuffer.clear();
    }
}

void EventsManager::sendEvent(const std::string& name,
                              const std::shared_ptr<ImgFrame>& imgFrame,
                              std::vector<std::shared_ptr<EventData>> data,
                              const std::vector<std::string>& tags,
                              const std::unordered_map<std::string, std::string>& extraData,
                              const std::string& deviceSerialNo) {
    // Create event
    auto event = std::make_unique<proto::event::Event>();
    event->set_nonce(createUUID());
    event->set_name(name);
    event->set_created_at(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    for(const auto& tag : tags) {
        event->add_tags(tag);
    }
    auto* extrasData = event->mutable_extras();
    for(const auto& entry : extraData) {
        extrasData->insert(entry);
    }

    if(imgFrame != nullptr) {
        auto fileData = std::make_shared<EventData>(imgFrame, "img.jpg");
        data.push_back(fileData);
    }
    event->set_expect_files_num(data.size());

    event->set_source_serial_number(deviceSerialNo.empty() ? deviceSerialNumber : deviceSerialNo);
    event->set_source_app_id(sourceAppId);
    event->set_source_app_identifier(sourceAppIdentifier);
    // Add event to buffer
    if(eventBuffer.size() <= queueSize) {
        std::lock_guard<std::mutex> lock(eventBufferMutex);
        auto eventMessage = std::make_unique<EventMessage>();
        eventMessage->data = std::move(data);
        eventMessage->event = std::move(event);
        eventBuffer.push_back(std::move(eventMessage));
    } else {
        logger::warn("Event buffer is full, dropping event");
    }
}

void EventsManager::sendSnap(const std::string& name,
                             const std::shared_ptr<ImgFrame>& imgFrame,
                             std::vector<std::shared_ptr<EventData>> data,
                             const std::vector<std::string>& tags,
                             const std::unordered_map<std::string, std::string>& extraData,
                             const std::string& deviceSerialNo) {
    std::vector<std::string> tagsTmp = tags;
    tagsTmp.emplace_back("snap");
    // exactly one image needs to be sent, either from imgFrame or from data
    bool send = false;
    if(imgFrame != nullptr && !data.empty()) {
        logger::error("For sending snap, provide either imgFrame or single image in data list, not both. Use sendEvent for multiple files");
    } else if(imgFrame == nullptr && data.empty()) {
        logger::error("No image or data provided");
    } else if(imgFrame == nullptr && !data.empty()) {
        if(data.size() > 1) {
            logger::error("More than one file provided in data. For sendings snaps, only one image file is allowed. Use sendEvent for multiple files");
        }
        if(data[0]->mimeType == "image/jpeg" || data[0]->mimeType == "image/png" || data[0]->mimeType == "image/webp") {
            send = true;
        }
		if(send == false) {
			logger::error("Only image files are allowed for snaps");
		}
    } else {
        send = true;
    }
    if(send) {
        sendEvent(name, imgFrame, data, tagsTmp, extraData, deviceSerialNo);
    }
    return;
}

void EventsManager::sendFile(const std::shared_ptr<EventData>& file, const std::string& url) {
    // if file struct contains byte data, send it, along with filename and mime type
    // if it file url, send it directly via url
    logger::info("Uploading file: to {}", url);
    auto header = cpr::Header{{"Authorization", "Bearer " + token}};
    cpr::Multipart fileM{};
    if(file->type != EventDataType::FILE_URL) {
        fileM = cpr::Multipart{{"file", cpr::Buffer{file->data.begin(), file->data.end(), file->fileName}, file->mimeType}};
        header["File-Size"] = std::to_string(std::size(file->data));
    } else {
        fileM = cpr::Multipart{{
            "file",
            cpr::File{file->data},
        }};
        header["File-Size"] = std::to_string(std::filesystem::file_size(file->data));
    }
    cpr::Response r = cpr::Post(url, header, fileM, cpr::VerifySsl(verifySsl));
    if(r.status_code != cpr::status::HTTP_OK) {
        logger::error("Failed to upload file: {} error code {}", r.text, r.status_code);
    }
    if(logResponse) {
        logger::info("Response: {}", r.text);
    }
}

void EventsManager::cacheEvents() {
    logger::info("Caching events");
    // for each event, create a unique directory, save protobuf message and associated files
    for(auto& eventM : eventBuffer) {
        auto& event = eventM->event;
        auto& data = eventM->data;
        std::filesystem::path p(cacheDir);
        std::string eventDir = p / ("event_" + event->name() + "_" + event->nonce());
        logger::info("Caching event to {}", eventDir);
        if(!std::filesystem::exists(cacheDir)) {
            std::filesystem::create_directories(cacheDir);
        }
        std::filesystem::create_directory(eventDir);
        std::ofstream eventFile(p / "event.pb", std::ios::binary);
        event->SerializeToOstream(&eventFile);
        for(auto& file : data) {
            file->toFile(eventDir);
        }
    }
    eventBuffer.clear();
}

void EventsManager::uploadCachedData() {
    // iterate over all directories in cacheDir, read event.pb and associated files, and send them
    logger::info("Uploading cached data");
    if(!checkConnection()) {
        return;
    }
    // check if cacheDir exists
    if(!std::filesystem::exists(cacheDir)) {
        logger::warn("Cache directory does not exist");
        return;
    }
    for(const auto& entry : std::filesystem::directory_iterator(cacheDir)) {
        if(entry.is_directory()) {
            const auto& eventDir = entry.path();
            std::ifstream eventFile(eventDir / "event.pb", std::ios::binary);
            proto::event::Event event;
            event.ParseFromIstream(&eventFile);
            std::vector<std::shared_ptr<EventData>> data;
            for(const auto& fileEntry : std::filesystem::directory_iterator(eventDir)) {
                if(fileEntry.is_regular_file() && fileEntry.path() != eventDir / "event.pb") {
                    auto fileData = std::make_shared<EventData>(fileEntry.path());
                    data.push_back(fileData);
                }
            }
            eventBuffer.push_back(std::make_unique<EventMessage>(EventMessage{std::make_shared<proto::event::Event>(event), data, eventDir}));
        }
    }
}

bool EventsManager::checkForCachedData() {
    // check if cacheDir exists
    if(!std::filesystem::exists(cacheDir)) {
        logger::warn("Cache directory does not exist");
        return false;
    }
    return std::any_of(
        std::filesystem::directory_iterator(cacheDir), std::filesystem::directory_iterator(), [](const auto& entry) { return entry.is_directory(); });
}

void EventsManager::setCacheDir(const std::string& cacheDir) {
    this->cacheDir = cacheDir;
}

void EventsManager::setUrl(const std::string& url) {
    this->url = url;
}

void EventsManager::setSourceAppId(const std::string& sourceAppId) {
    this->sourceAppId = sourceAppId;
}

void EventsManager::setSourceAppIdentifier(const std::string& sourceAppIdentifier) {
    this->sourceAppIdentifier = sourceAppIdentifier;
}

void EventsManager::setToken(const std::string& token) {
    this->token = token;
}

bool EventsManager::checkConnection() {
    cpr::Response r = cpr::Get(cpr::Url{url + "/health"}, cpr::VerifySsl(verifySsl));
    if(r.status_code != cpr::status::HTTP_OK) {
        logger::error("Failed to connect to events service: {} {}", r.text, r.status_code);
        return false;
    }
    logger::info("Connected to events service");
    return true;
}
std::string EventsManager::createUUID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    std::uniform_int_distribution<> dis2(8, 11);

    std::stringstream ss;
    int i = 0;
    ss << std::hex;
    for(i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for(i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    ss << "-4";
    for(i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    ss << dis2(gen);
    for(i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for(i = 0; i < 12; i++) {
        ss << dis(gen);
    };
    return ss.str();
}
void EventsManager::setQueueSize(uint64 queueSize) {
    this->queueSize = queueSize;
}
void EventsManager::setLogResponse(bool logResponse) {
    this->logResponse = logResponse;
}
void EventsManager::setDeviceSerialNumber(const std::string& deviceSerialNumber) {
    this->deviceSerialNumber = deviceSerialNumber;
}
void EventsManager::setVerifySsl(bool verifySsl) {
    this->verifySsl = verifySsl;
}
void EventsManager::setCacheIfCannotSend(bool cacheIfCannotSend) {
	this->cacheIfCannotSend = cacheIfCannotSend;
}
}  // namespace utility
}  // namespace dai
#else
namespace dai {
namespace utility {
EventsManager::EventsManager(const std::string& deviceSerialNumber) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::sendEvent(const std::string& name,
                              const std::unordered_map<std::string, std::string>& data,
                              const std::vector<std::string>& tags,
                              const std::vector<FileData>& files,
                              const std::shared_ptr<ADatatype>& daiMsg) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::sendSnap(const std::string& name,
                             const std::vector<std::string>& tags,
                             const std::vector<FileData>& files,
                             const std::unordered_map<std::string, std::string>& extraData) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setUrl(const std::string& url) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setSourceAppId(const std::string& sourceAppId) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setSourceAppIdentifier(const std::string& sourceAppIdentifier) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setToken(const std::string& token) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setQueueSize(unsigned long queueSize) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setLogResponse(bool logResponse) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setDeviceSerialNumber(const std::string& deviceSerialNumber) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setVerifySsl(bool verifySsl) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setCacheDir(const std::string& cacheDir) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::cacheEvents() {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::uploadCachedData() {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
void EventsManager::setCacheIfCannotSend(bool cacheIfCannotSend) {
    logger::warn("EventsManager is disabled, please enable DEPTHAI_ENABLE_CURL in CMake to use this feature");
}
}  // namespace utility
}  // namespace dai
#endif
