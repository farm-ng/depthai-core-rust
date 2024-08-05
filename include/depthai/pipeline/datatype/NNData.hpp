#pragma once

#include <algorithm>
#include <chrono>
#include <limits>
#include <optional>
#include <unordered_map>
#include <vector>

#include "Buffer.hpp"
#include "depthai/common/TensorInfo.hpp"
#include "depthai/utility/VectorMemory.hpp"
#include "depthai/utility/span.hpp"
#include "xtensor/xmanipulation.hpp"

#if defined(__clang__)
    #if __has_warning("-Wswitch-enum")
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wswitch-enum"
    #endif
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-enum"
#elif defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4061)
#endif
#if defined(ON)
    #define _ON_DEF ON
    #undef ON
#endif
#ifdef DEPTHAI_XTENSOR_SUPPORT
    #include "xtensor/xadapt.hpp"
    #include "xtensor/xarray.hpp"
#endif
#if defined(_ON_DEF)
    #define ON _ON_DEF
#endif
#if defined(__clang__)
    #if __has_warning("-Wswitch-enum")
        #pragma clang diagnostic pop
    #endif
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

namespace dai {

/**
 * NNData message. Carries tensors and their metadata
 */
class NNData : public Buffer {
    static constexpr int DATA_ALIGNMENT = 64;
    static uint16_t fp32_to_fp16(float);
    static float fp16_to_fp32(uint16_t);

    // store the data
    // uint8_t
    // std::unordered_map<std::string, std::vector<std::uint8_t>> u8Data;
    // // FP16
    // std::unordered_map<std::string, std::vector<std::uint16_t>> fp16Data;

   public:
    std::vector<TensorInfo> tensors;
    unsigned int batchSize;
    /**
     * Construct NNData message.
     */
    NNData() = default;
    NNData(size_t size);
    virtual ~NNData() = default;

    // // Expose
    // // uint8_t
    // /**
    //  * Set a layer with datatype U8.
    //  * @param name Name of the layer
    //  * @param data Data to store
    //  */
    // [[deprecated("Use 'addTensor()' instead")]] NNData& setLayer(const std::string& name, std::vector<std::uint8_t> data);

    // /**
    //  * Set a layer with datatype U8. Integers are cast to bytes.
    //  * @param name Name of the layer
    //  * @param data Data to store
    //  */
    // [[deprecated("Use 'addTensor()' instead")]] NNData& setLayer(const std::string& name, const std::vector<int>& data);

    // // fp16
    // /**
    //  * Set a layer with datatype FP16. Float values are converted to FP16.
    //  * @param name Name of the layer
    //  * @param data Data to store
    //  */
    // [[deprecated("Use 'addTensor()' instead")]] NNData& setLayer(const std::string& name, std::vector<float> data);

    // /**
    //  * Set a layer with datatype FP16. Double values are converted to FP16.
    //  * @param name Name of the layer
    //  * @param data Data to store
    //  */
    // [[deprecated("Use 'addTensor()' instead")]] NNData& setLayer(const std::string& name, std::vector<double> data);

    // getters
    /**
     * @returns Names of all layers added
     */
    std::vector<std::string> getAllLayerNames() const;

    /**
     * @returns All layers and their information
     */
    std::vector<TensorInfo> getAllLayers() const;

    /**
     * Retrieve tensor information
     * @param name Name of the tensor
     * @returns Tensor information
     */
    std::optional<TensorInfo> getTensorInfo(const std::string& name) const;

    // TODO(Morato) - deprecate this
    /**
     * Retrieve layers tensor information
     * @param name Name of the layer
     * @param[out] tensor Outputs tensor information of that layer
     * @returns True if layer exists, false otherwise
     */
    bool getLayer(const std::string& name, TensorInfo& tensor) const;

    /**
     * Checks if given layer exists
     * @param name Name of the layer
     * @returns True if layer exists, false otherwise
     */
    bool hasLayer(const std::string& name) const;

    /**
     * Retrieve datatype of a layers tensor
     * @param name Name of the layer
     * @param[out] datatype Datatype of layers tensor
     * @returns True if layer exists, false otherwise
     */
    bool getLayerDatatype(const std::string& name, TensorInfo::DataType& datatype) const;

    // // uint8
    // /**
    //  * Convenience function to retrieve U8 data from layer
    //  * @param name Name of the layer
    //  * @returns U8 binary data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<std::uint8_t> getLayerUInt8(const std::string& name) const;

    // // fp16
    // /**
    //  * Convenience function to retrieve float values from layers FP16 tensor
    //  * @param name Name of the layer
    //  * @returns Float data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<float> getLayerFp16(const std::string& name) const;

    // // int32
    // /**
    //  * Convenience function to retrieve INT32 values from layers tensor
    //  * @param name Name of the layer
    //  * @returns INT32 data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<std::int32_t> getLayerInt32(const std::string& name) const;

    // // first layer
    // /**
    //  * Convenience function to retrieve U8 data from first layer
    //  * @returns U8 binary data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<std::uint8_t> getFirstLayerUInt8() const;

    // /**
    //  * Convenience function to retrieve float values from first layers FP16 tensor
    //  * @returns Float data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<float> getFirstLayerFp16() const;

    // /**
    //  * Convenience function to retrieve INT32 values from first layers tensor
    //  * @returns INT32 data
    //  */
    // [[deprecated("Use 'getTensor()' instead")]] std::vector<std::int32_t> getFirstLayerInt32() const;

    /**
     * Emplace a tensor
     * This function allocates memory for the tensor and return over the said memory.
     * It is up to the caller to fill the memory out with meaningful data.
     * @return Span over the allocated memory
     */
    span<std::uint8_t> emplaceTensor(TensorInfo& tensor);

#ifdef DEPTHAI_XTENSOR_SUPPORT
    /**
     * Set a layer with datatype FP16. Double values are converted to FP16.
     * @param name Name of the layer
     * @param data Data to store
     */
    template <typename _Ty = double>
    NNData& addTensor(const std::string& name, const std::vector<_Ty>& data) {
        return addTensor<_Ty>(name, xt::adapt(data, std::vector<size_t>{1, data.size()}));
    };

    /**
     * Add a tensor. Float values are converted to FP16 and integers are cast to bytes.
     * @param name Name of the tensor
     * @param tensor Tensor to store
     */
    template <typename _Ty = double>
    NNData& addTensor(const std::string& name, const xt::xarray<_Ty>& tensor) {
        static_assert(std::is_integral<_Ty>::value || std::is_floating_point<_Ty>::value, "Tensor type needs to be integral or floating point");

        // Check if data is vector type of data
        if(std::dynamic_pointer_cast<VectorMemory>(data) == nullptr) {
            auto prev = std::vector<uint8_t>(data->getData().begin(), data->getData().end());
            data = std::make_shared<VectorMemory>(std::move(prev));
        }
        auto vecData = std::dynamic_pointer_cast<VectorMemory>(data);

        // Get size in bytes of the converted tensor data, u8 for integral and fp16 for floating point
        const size_t sConvertedData = std::is_integral<_Ty>::value ? tensor.size() : 2 * tensor.size();

        // Append bytes so that each new tensor is DATA_ALIGNMENT aligned
        size_t remainder = (vecData->end() - vecData->begin()) % DATA_ALIGNMENT;
        if(remainder > 0) {
            vecData->insert(vecData->end(), DATA_ALIGNMENT - remainder, 0);
        }

        // Then get offset to beginning of data
        size_t offset = vecData->end() - vecData->begin();

        // Reserve space
        vecData->resize(offset + sConvertedData);

        // Convert data to u8 or fp16 and write to data
        if(std::is_integral<_Ty>::value) {
            for(uint32_t i = 0; i < tensor.size(); i++) {
                vecData->data()[i + offset] = (uint8_t)tensor.data()[i];
            }
        } else {
            for(uint32_t i = 0; i < tensor.size(); i++) {
                *(uint16_t*)(&vecData->data()[2 * i + offset]) = fp32_to_fp16(tensor.data()[i]);
            }
        }

        // Add entry in tensors
        TensorInfo info;
        info.name = name;
        info.offset = static_cast<unsigned int>(offset);
        info.dataType = std::is_integral<_Ty>::value ? TensorInfo::DataType::U8F : TensorInfo::DataType::FP16;
        info.numDimensions = tensor.dimension();
        for(uint32_t i = 0; i < tensor.dimension(); i++) {
            info.dims.push_back(tensor.shape()[i]);
            info.strides.push_back(tensor.strides()[i] * sizeof(uint16_t));
        }

        tensors.push_back(info);
        return *this;
    }

    /**
     * Convenience function to retrieve values from a tensor
     * @returns xt::xarray<_Ty> tensor
     */
    template <typename _Ty>
    xt::xarray<_Ty> getTensor(const std::string& name, bool dequantize = false) {
        const auto it = std::find_if(tensors.begin(), tensors.end(), [&name](const TensorInfo& ti) { return ti.name == name; });

        if(it == tensors.end()) throw std::runtime_error("Tensor does not exist");

        std::vector<size_t> dims;
        for(const auto v : it->dims) {
            dims.push_back(v);
        }

        std::vector<size_t> strides;
        for(const auto v : it->strides) {
            strides.push_back(v);
        }

        xt::xarray<_Ty, xt::layout_type::row_major> tensor(dims);

        switch(it->dataType) {
            case TensorInfo::DataType::U8F:
                for(uint32_t i = 0; i < tensor.size(); i++) {
                    tensor.data()[i] = data->getData().data()[it->offset + i];
                }
                break;
            case TensorInfo::DataType::I8:
                for(uint32_t i = 0; i < tensor.size(); i++) {
                    tensor.data()[i] = reinterpret_cast<int8_t*>(data->getData().data())[it->offset + i];
                }
                break;
            case TensorInfo::DataType::INT:
                for(uint32_t i = 0; i < tensor.size(); i++) {
                    tensor.data()[i] = reinterpret_cast<int32_t*>(data->getData().data())[it->offset / sizeof(int32_t) + i];
                }
                break;
            case TensorInfo::DataType::FP16:
                for(uint32_t i = 0; i < tensor.size(); i++) {
                    tensor.data()[i] = fp16_to_fp32(reinterpret_cast<uint16_t*>(data->getData().data())[it->offset / sizeof(uint16_t) + i]);
                }
                break;
            case TensorInfo::DataType::FP32:
                for(uint32_t i = 0; i < tensor.size(); i++) {
                    tensor.data()[i] = reinterpret_cast<float_t*>(data->getData().data())[it->offset / sizeof(float_t) + i];
                }
                break;
        }
        if(dequantize) {
            if(it->quantization) {
                tensor = (tensor - it->qpZp) * it->qpScale;
            }
        }
        return tensor;
    }

    /**
     * Convenience function to retrieve values from a tensor
     * @returns xt::xarray<_Ty> tensor
     */
    template <typename _Ty>
    xt::xarray<_Ty> getTensor(const std::string& name, TensorInfo::StorageOrder order, bool dequantize = false) {
        // Get tensor
        xt::xarray<_Ty> tensor = getTensor<_Ty>(name, dequantize);

        const auto it = std::find_if(tensors.begin(), tensors.end(), [&name](const TensorInfo& ti) { return ti.name == name; });

        // Reshape
        std::vector<int> fromShape = tensor.shape();
        std::vector<int> fromOrder;
        std::vector<int> toOrder;

        int from = static_cast<int>(it->order);
        int to = static_cast<int>(order);

        while(to > 0) {
            fromOrder.push_back(to % 10);
            to /= 10;
        }

        while(from > 0) {
            toOrder.push_back(from % 10);
            from /= 10;
        }

        // Just permute
        if(fromOrder.size() == toOrder.size()) {
            std::vector<int> permutation;
            for(int dim : fromOrder) {
                auto it = std::find(toOrder.begin(), toOrder.end(), dim);
                int index = std::distance(toOrder.begin(), it);
                if(index == static_cast<int>(toOrder.size())) {
                    throw std::runtime_error("Cannot permute dimensions");
                }
                permutation.push_back(index);
            }

            tensor = xt::transpose(tensor, permutation);
        }

        // Expand and permute
        if(fromOrder.size() < toOrder.size()) {
            std::vector<int> permutation;
            std::vector<int> expansion;

            for(int dim : fromOrder) {
                auto it = std::find(toOrder.begin(), toOrder.end(), dim);
                int index = std::distance(toOrder.begin(), it);
                if(index != static_cast<int>(toOrder.size())) {
                    permutation.push_back(index);
                }
            }

            for(int i = 0; i < static_cast<int>(toOrder.size()); ++i) {
                auto it = std::find(fromOrder.begin(), fromOrder.end(), i);
                if(it == fromOrder.end()) {
                    expansion.push_back(i);
                }
            }

            tensor = xt::expand_dims(tensor, expansion);
            tensor = xt::transpose(tensor, permutation);
        }

        // Squeeze and permute
        if(fromOrder.size() > toOrder.size()) {
            std::vector<int> permutation;
            std::vector<int> squeeze;

            for(int i = 0; i < static_cast<int>(fromOrder.size()); ++i) {
                int dim = fromOrder[i];
                auto it = std::find(toOrder.begin(), toOrder.end(), dim);
                int index = std::distance(toOrder.begin(), it);
                if(it == toOrder.end()) {
                    if(tensor.shape()[i] != 1) {
                        throw std::runtime_error("Cannot squeeze dimension with size != 1");
                    }
                    squeeze.push_back(i);
                } else {
                    permutation.push_back(index);
                }
            }

            tensor = xt::squeeze(tensor, squeeze);
            tensor = xt::transpose(tensor, permutation);
        }

        return tensor;
    }

    /**
     * Get the datatype of a given tensor
     * @returns TensorInfo::DataType tensor datatype
     */
    TensorInfo::DataType getTensorDatatype(const std::string& name);

    /**
     * Get the datatype of the first tensor
     * @returns TensorInfo::DataType tensor datatype
     */
    TensorInfo::DataType getFirstTensorDatatype();

    /**
     * Convenience function to retrieve values from the first tensor
     * @returns xt::xarray<_Ty> tensor
     */
    template <typename _Ty>
    xt::xarray<_Ty> getFirstTensor(bool dequantize = false) {
        if(!tensors.empty()) {
            return getTensor<_Ty>(tensors[0].name, dequantize);
        }

        return {};
    }
#endif
    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) const override {
        metadata = utility::serialize(*this);
        datatype = DatatypeEnum::NNData;
    };

    DEPTHAI_SERIALIZE(NNData, Buffer::sequenceNum, Buffer::ts, Buffer::tsDevice, tensors, batchSize);
};

}  // namespace dai
