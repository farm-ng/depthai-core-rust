#include "depthai/nn_archive/NNArchive.hpp"

// internal private
#include "common/ModelType.hpp"
#include "utility/ArchiveUtil.hpp"
#include "utility/ErrorMacros.hpp"

namespace dai {

NNArchive::NNArchive(const std::string& archivePath, NNArchiveOptions options) : archiveOptions(options) {
    // Make sure archive exits
    if(!std::filesystem::exists(archivePath)) DAI_CHECK_V(false, "Archive file does not exist: {}", archivePath);

    // Read config
    archiveConfigPtr.reset(new NNArchiveConfig(archivePath, archiveOptions.compression()));

    // Based on the config, read model path in archive
    std::string modelPathInArchive = archiveConfigPtr->getConfigV1()->model.metadata.path;

    // Read archive type
    modelType = model::readModelType(modelPathInArchive);

    switch(modelType) {
        case model::ModelType::BLOB:
            blobPtr.reset(new OpenVINO::Blob(readModelFromArchive(archivePath, modelPathInArchive)));
            break;
        case model::ModelType::SUPERBLOB:
            superblobPtr.reset(new OpenVINO::SuperBlob(readModelFromArchive(archivePath, modelPathInArchive)));
            break;
        case model::ModelType::DLC:
        case model::ModelType::OTHER:
            unpackArchiveInDirectory(archivePath,
                                     (std::filesystem::path(archiveOptions.extractFolder()) / std::filesystem::path(archivePath).filename()).string());
            unpackedModelPath =
                (std::filesystem::path(archiveOptions.extractFolder()) / std::filesystem::path(archivePath).filename() / modelPathInArchive).string();
            break;
        case model::ModelType::NNARCHIVE:
            DAI_CHECK_V(false, "NNArchive inside NNArchive is not supported. Please unpack the inner archive first.");
            break;
        default:
            DAI_CHECK(false, "Unknown archive type");
            break;
    }
}

std::optional<OpenVINO::Blob> NNArchive::getBlob() const {
    switch(modelType) {
        case model::ModelType::BLOB:
            return *blobPtr;
            break;
        case model::ModelType::SUPERBLOB:
        case model::ModelType::DLC:
        case model::ModelType::OTHER:
            return std::nullopt;
            break;
        case model::ModelType::NNARCHIVE:
            DAI_CHECK_V(false, "NNArchive inside NNArchive is not supported. Please unpack the inner archive first.");
            break;
        default:
            DAI_CHECK(false, "Unknown archive type");
            break;
    }
}

std::optional<OpenVINO::SuperBlob> NNArchive::getSuperBlob() const {
    switch(modelType) {
        case model::ModelType::SUPERBLOB:
            return *superblobPtr;
            break;
        case model::ModelType::BLOB:
        case model::ModelType::OTHER:
        case model::ModelType::DLC:
            return std::nullopt;
            break;
        case model::ModelType::NNARCHIVE:
            DAI_CHECK_V(false, "NNArchive inside NNArchive is not supported. Please unpack the inner archive first.");
            break;
        default:
            DAI_CHECK(false, "Unknown archive type");
            break;
    }
}

std::optional<std::string> NNArchive::getModelPath() const {
    switch(modelType) {
        case model::ModelType::OTHER:
        case model::ModelType::DLC:
            return unpackedModelPath;
            break;
        case model::ModelType::BLOB:
        case model::ModelType::SUPERBLOB:
            return std::nullopt;
            break;
        case model::ModelType::NNARCHIVE:
            DAI_CHECK_V(false, "NNArchive inside NNArchive is not supported. Please unpack the inner archive first.");
            break;
        default:
            DAI_CHECK(false, "Unknown archive type");
            break;
    }
}

model::ModelType NNArchive::getModelType() const {
    return modelType;
}

const NNArchiveConfig& NNArchive::getConfig() const {
    return *archiveConfigPtr;
}

std::vector<uint8_t> NNArchive::readModelFromArchive(const std::string& archivePath, const std::string& modelPathInArchive) const {
    utility::ArchiveUtil archive(archivePath, archiveOptions.compression());
    std::vector<uint8_t> modelBytes;
    const bool success = archive.readEntry(modelPathInArchive, modelBytes);
    DAI_CHECK_V(success, "No model {} found in NNArchive {} | Please check your NNArchive.", modelPathInArchive, archivePath);
    return modelBytes;
}

void NNArchive::unpackArchiveInDirectory(const std::string& archivePath, const std::string& directory) const {
    utility::ArchiveUtil archive(archivePath, archiveOptions.compression());
    archive.unpackArchiveInDirectory(directory);
}

}  // namespace dai