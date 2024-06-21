#!/usr/bin/env python3

"""
The code is the same as for Tiny Yolo V3 and V4, the only difference is the blob file
- Tiny YOLOv3: https://github.com/david8862/keras-YOLOv3-model-set
- Tiny YOLOv4: https://github.com/TNTWEN/OpenVINO-YOLOV4
"""

from pathlib import Path
import sys
import cv2
import depthai as dai
import numpy as np
import time

# Get argument first
nnPath = str(
    (
        Path(__file__).parent
        # / Path("/home/matevz/Downloads/yolo-v4-tiny-tf_openvino_2021.4_6shave.blob")
        / Path("/home/matevz/Downloads/yolov10n-simplified.blob")
    )
    .resolve()
    .absolute()
)
if 1 < len(sys.argv):
    arg = sys.argv[1]
    if arg == "yolo3":
        nnPath = str(
            (
                Path(__file__).parent
                / Path("../models/yolo-v3-tiny-tf_openvino_2021.4_6shave.blob")
            )
            .resolve()
            .absolute()
        )
    elif arg == "yolo4":
        nnPath = str(
            (
                Path(__file__).parent
                / Path("../models/yolo-v4-tiny-tf_openvino_2021.4_6shave.blob")
            )
            .resolve()
            .absolute()
        )
    else:
        nnPath = arg
else:
    print(
        "Using Tiny YoloV4 model. If you wish to use Tiny YOLOv3, call 'tiny_yolo.py yolo3'"
    )

if not Path(nnPath).exists():
    import sys

    raise FileNotFoundError(
        f'Required file/s not found, please run "{sys.executable} install_requirements.py"'
    )

# Create a blob from the path and analyze the network

# tiny yolo v4 label texts
labelMap = [
    "person",
    "bicycle",
    "car",
    "motorbike",
    "aeroplane",
    "bus",
    "train",
    "truck",
    "boat",
    "traffic light",
    "fire hydrant",
    "stop sign",
    "parking meter",
    "bench",
    "bird",
    "cat",
    "dog",
    "horse",
    "sheep",
    "cow",
    "elephant",
    "bear",
    "zebra",
    "giraffe",
    "backpack",
    "umbrella",
    "handbag",
    "tie",
    "suitcase",
    "frisbee",
    "skis",
    "snowboard",
    "sports ball",
    "kite",
    "baseball bat",
    "baseball glove",
    "skateboard",
    "surfboard",
    "tennis racket",
    "bottle",
    "wine glass",
    "cup",
    "fork",
    "knife",
    "spoon",
    "bowl",
    "banana",
    "apple",
    "sandwich",
    "orange",
    "broccoli",
    "carrot",
    "hot dog",
    "pizza",
    "donut",
    "cake",
    "chair",
    "sofa",
    "pottedplant",
    "bed",
    "diningtable",
    "toilet",
    "tvmonitor",
    "laptop",
    "mouse",
    "remote",
    "keyboard",
    "cell phone",
    "microwave",
    "oven",
    "toaster",
    "sink",
    "refrigerator",
    "book",
    "clock",
    "vase",
    "scissors",
    "teddy bear",
    "hair drier",
    "toothbrush",
]

syncNN = False

device = dai.Device()

# Create pipeline
pipeline = dai.Pipeline(device)

# Define sources and outputs
camRgb = pipeline.create(dai.node.ColorCamera)
detectionNetwork = pipeline.create(dai.node.YoloDetectionNetwork)

# Properties
camRgb.setPreviewSize(640, 640)
camRgb.setResolution(dai.ColorCameraProperties.SensorResolution.THE_1080_P)
camRgb.setInterleaved(False)
camRgb.setColorOrder(dai.ColorCameraProperties.ColorOrder.BGR)
camRgb.setFps(40)

# Network specific settings
detectionNetwork.setConfidenceThreshold(0.8)
detectionNetwork.setNumClasses(80)
detectionNetwork.setCoordinateSize(4)
# detectionNetwork.setAnchors([10, 14, 23, 27, 37, 58, 81, 82, 135, 169, 344, 319])
# detectionNetwork.setAnchorMasks({"side26": [1, 2, 3], "side13": [3, 4, 5]})
# detectionNetwork.setIouThreshold(0.5)
detectionNetwork.setBlobPath(nnPath)
detectionNetwork.setNumInferenceThreads(2)
detectionNetwork.input.setBlocking(False)
detectionNetwork.build()

# Linking
camRgb.preview.link(detectionNetwork.input)

# Output queues will be used to get the rgb frames and nn data from the outputs defined above
qRgb = camRgb.preview.createOutputQueue(maxSize=4, blocking=False)
qDet = detectionNetwork.out.createOutputQueue(maxSize=4, blocking=False)

# Connect to device and start pipeline
pipeline.start()

frame = None
detections = []
startTime = time.monotonic()
counter = 0
color2 = (255, 255, 255)


# nn data, being the bounding box locations, are in <0..1> range - they need to be normalized with frame width/height
def frameNorm(frame, bbox):
    normVals = np.full(len(bbox), frame.shape[0])
    normVals[::2] = frame.shape[1]
    return (np.clip(np.array(bbox), 0, 1) * normVals).astype(int)


def displayFrame(name, frame):
    color = (255, 0, 0)
    for detection in detections:
        bbox = frameNorm(
            frame, (detection.xmin, detection.ymin, detection.xmax, detection.ymax)
        )
        cv2.putText(
            frame,
            labelMap[detection.label],
            (bbox[0] + 10, bbox[1] + 20),
            cv2.FONT_HERSHEY_TRIPLEX,
            0.5,
            255,
        )
        cv2.putText(
            frame,
            f"{int(detection.confidence * 100)}%",
            (bbox[0] + 10, bbox[1] + 40),
            cv2.FONT_HERSHEY_TRIPLEX,
            0.5,
            255,
        )
        cv2.rectangle(frame, (bbox[0], bbox[1]), (bbox[2], bbox[3]), color, 2)
    # Show the frame
    cv2.imshow(name, frame)


while True:
    if syncNN:
        inRgb = qRgb.get()
        inDet = qDet.get()
    else:
        inRgb = qRgb.tryGet()
        inDet = qDet.tryGet()

    if inRgb is not None:
        frame = inRgb.getCvFrame()
        cv2.putText(
            frame,
            "NN fps: {:.2f}".format(counter / (time.monotonic() - startTime)),
            (2, frame.shape[0] - 4),
            cv2.FONT_HERSHEY_TRIPLEX,
            0.4,
            color2,
        )

    if inDet is not None:
        detections = inDet.detections
        counter += 1

    if frame is not None:
        displayFrame("rgb", frame)
    cv2.waitKey(1)
