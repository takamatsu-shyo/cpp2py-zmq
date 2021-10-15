import zmq
import numpy
from PIL import Image
import io
import cv2

context = zmq.Context()
receiver = context.socket(zmq.SUB)
receiver.connect("tcp://localhost:9999")
receiver.setsockopt_string(zmq.SUBSCRIBE, "")

while(True):
    image_bytes = receiver.recv()
    image = numpy.array(Image.open(io.BytesIO(image_bytes)))
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    cv2.imshow("Py Frame", image) 
    cv2.waitKey(1)
