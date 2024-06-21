#include <memory>
#include <unordered_map>

#include "DatatypeBindings.hpp"
#include "depthai/common/Point2f.hpp"
#include "pipeline/CommonBindings.hpp"

// depthai
#include "depthai/pipeline/datatype/ImageManipConfigV2.hpp"

// pybind
#include <pybind11/chrono.h>
#include <pybind11/numpy.h>

// #include "spdlog/spdlog.h"

void bind_imagemanipconfigv2(pybind11::module& m, void* pCallstack) {
    using namespace dai;

    py::class_<ImageManipConfigV2, Py<ImageManipConfigV2>, Buffer, std::shared_ptr<ImageManipConfigV2>> imageManipConfig(
        m, "ImageManipConfigV2", DOC(dai, ImageManipConfigV2));
    py::enum_<ImageManipConfigV2::ResizeMode> resizeMode(imageManipConfig, "ResizeMode");

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // Call the rest of the type defines, then perform the actual bindings
    Callstack* callstack = (Callstack*)pCallstack;
    auto cb = callstack->top();
    callstack->pop();
    cb(m, pCallstack);
    // Actual bindings
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    resizeMode
        .value("NONE", ImageManipConfigV2::ResizeMode::NONE)
        .value("LETTERBOX", ImageManipConfigV2::ResizeMode::LETTERBOX)
        .value("CENTER_CROP", ImageManipConfigV2::ResizeMode::CENTER_CROP)
        .value("STRETCH", ImageManipConfigV2::ResizeMode::STRETCH);

    // Message

    imageManipConfig
        .def(py::init<>())
        // New API Setters
        .def("crop", &ImageManipConfigV2::crop, py::arg("x"), py::arg("y"), py::arg("w"), py::arg("h"), DOC(dai, ImageManipConfigV2, crop))
        .def("cropRotatedRect", &ImageManipConfigV2::cropRotatedRect, py::arg("rect"), py::arg("normalizedCoords"), DOC(dai, ImageManipConfigV2, cropRotatedRect))
        .def("resize", &ImageManipConfigV2::resize, py::arg("w"), py::arg("h"), DOC(dai, ImageManipConfigV2, resize))
        .def("scale",
             [](ImageManipConfigV2& self, float scale) { return self.scale(scale); },
             py::arg("scale"),
             DOC(dai, ImageManipConfigV2, scale))
        .def("scale",
             [](ImageManipConfigV2& self, float scaleX, float scaleY) { return self.scale(scaleX, scaleY); },
             py::arg("scaleX"),
             py::arg("scaleY"),
             DOC(dai, ImageManipConfigV2, scale))
        .def("flipHorizontal", &ImageManipConfigV2::flipHorizontal, DOC(dai, ImageManipConfigV2, flipHorizontal))
        .def("flipVertical", &ImageManipConfigV2::flipVertical, DOC(dai, ImageManipConfigV2, flipVertical))
        .def("rotateDeg",
             static_cast<ImageManipConfigV2& (ImageManipConfigV2::*)(float)>(&ImageManipConfigV2::rotateDeg),
             py::arg("angle"),
             DOC(dai, ImageManipConfigV2, rotateDeg))
        .def("rotateDeg",
             static_cast<ImageManipConfigV2& (ImageManipConfigV2::*)(float, Point2f)>(&ImageManipConfigV2::rotateDeg),
             py::arg("angle"),
             py::arg("center"),
             DOC(dai, ImageManipConfigV2, rotateDeg))
        .def("transformAffine", &ImageManipConfigV2::transformAffine, py::arg("mat"), DOC(dai, ImageManipConfigV2, transformAffine))
        .def("transformPerspective", &ImageManipConfigV2::transformPerspective, py::arg("mat"), DOC(dai, ImageManipConfigV2, transformPerspective))
        .def("transformFourPoints", &ImageManipConfigV2::transformFourPoints, py::arg("src"), py::arg("dst"), py::arg("normalizedCoords"), DOC(dai, ImageManipConfigV2, transformFourPoints))
        .def(
            "setOutputSize",
            &ImageManipConfigV2::setOutputSize,
            py::arg("w"),
            py::arg("h"),
            py::arg("mode"),
            DOC(dai, ImageManipConfigV2, setOutputSize))
        .def("setReusePreviousImage", &ImageManipConfigV2::setReusePreviousImage, py::arg("reuse"), DOC(dai, ImageManipConfigV2, setReusePreviousImage))
        .def("setSkipCurrentImage", &ImageManipConfigV2::setSkipCurrentImage, py::arg("skip"), DOC(dai, ImageManipConfigV2, setSkipCurrentImage))
        .def("setFrameType", &ImageManipConfigV2::setFrameType, py::arg("type"), DOC(dai, ImageManipConfigV2, setFrameType))
        .def("setColormap",
             static_cast<ImageManipConfigV2& (ImageManipConfigV2::*)(Colormap)>(&ImageManipConfigV2::setColormap),
             py::arg("colormap"),
             DOC(dai, ImageManipConfigV2, setColormap));
}
