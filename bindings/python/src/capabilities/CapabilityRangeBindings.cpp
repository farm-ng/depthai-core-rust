#include "CapabilityRangeBindings.hpp"

// for std::optional and std::variant support
#include <pybind11/stl.h>

// depthai
#include "depthai/capabilities/CapabilityRange.hpp"

void CapabilityRangeBindings::bind(pybind11::module& m, void* pCallstack) {
    using namespace dai;

#define ADD_TYPE(NICE_NAME, ...)                                                                                                                 \
    py::class_<CapabilityRange<__VA_ARGS__>> capabilityRange##NICE_NAME(m, "CapabilityRange" #NICE_NAME, DOC(dai, CapabilityRange##NICE_NAME));  \
    capabilityRange##NICE_NAME.def("fixed", &CapabilityRange<__VA_ARGS__>::fixed, DOC(dai, CapabilityRange##NICE_NAME, fixed));                  \
    capabilityRange##NICE_NAME.def(                                                                                                              \
        "minMax",                                                                                                                                \
        static_cast<void (CapabilityRange<__VA_ARGS__>::*)(const std::pair<__VA_ARGS__, __VA_ARGS__>&)>(&CapabilityRange<__VA_ARGS__>::minMax),  \
        DOC(dai, CapabilityRange##NICE_NAME, minMax));                                                                                           \
    capabilityRange##NICE_NAME.def(                                                                                                              \
        "minMax",                                                                                                                                \
        static_cast<void (CapabilityRange<__VA_ARGS__>::*)(const std::tuple<__VA_ARGS__, __VA_ARGS__>&)>(&CapabilityRange<__VA_ARGS__>::minMax), \
        DOC(dai, CapabilityRange##NICE_NAME, minMax, 2));                                                                                        \
    capabilityRange##NICE_NAME.def(                                                                                                              \
        "minMax",                                                                                                                                \
        static_cast<void (CapabilityRange<__VA_ARGS__>::*)(const __VA_ARGS__&, const __VA_ARGS__&)>(&CapabilityRange<__VA_ARGS__>::minMax),      \
        DOC(dai, CapabilityRange##NICE_NAME, minMax, 3));                                                                                        \
    capabilityRange##NICE_NAME.def("discrete", &CapabilityRange<__VA_ARGS__>::discrete, DOC(dai, CapabilityRange##NICE_NAME, discrete));

    ADD_TYPE(Uint, uint32_t);
    ADD_TYPE(UintPair, std::pair<uint32_t, uint32_t>);

#undef ADD_TYPE

    // Call the rest of the type defines, then perform the actual bindings
    Callstack* callstack = (Callstack*)pCallstack;
    auto cb = callstack->top();
    callstack->pop();
    cb(m, pCallstack);
}