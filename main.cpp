#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <zmq.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

    // Setup ZMQ publisher
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int bind = zmq_bind(publisher, "tcp://*:9999");


    // Setup frame capture from USB camera
    VideoCapture cap;
    int camId = 0;
    cap.open(camId);
    if(!cap.isOpened()){
        cout << "Camera not found at " << camId;
        return -1;
    }

    Mat frame;
    int height = frame.rows;
    int width = frame.cols;

    vector<uchar> buffer;
    //imencode(".jpg", frame, buffer);

    while(true){

        // Capture and debug window
        bool grabSuccess = cap.read(frame);
        if( grabSuccess == false){
            cout << "Failed to grab a frame";
            break;
        }
        imshow("frame", frame);


        // ZMQ publisher
        imencode(".jpg", frame, buffer);
        zmq_send(publisher, buffer.data(), buffer.size(), ZMQ_NOBLOCK);


        if(waitKey(10) == 27){
            cout << "quit by esc";
            break;
        }

    }

    return 0;
}
