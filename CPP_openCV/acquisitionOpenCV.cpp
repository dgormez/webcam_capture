#include <vector>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <math.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>


#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


using namespace std;
using namespace cv;


double get_wall_time();

int main(int argc, char *argv[])
{
    //  Start Timers
    double wall0 = get_wall_time();
    unsigned int microseconds = 250000; // Micro seconds and not motherfucking milliseconds

    VideoCapture capture0(0); // open the default camera
    VideoCapture capture1(1); // open camera 1
    VideoCapture capture2(2); // open camera 2
    VideoCapture capture3(3); // open camera 3

    if(!capture0.isOpened())  // check if we succeeded
        cout << "Problem opening camera 0" << endl;

    if(!capture1.isOpened())  // check if we succeeded
        cout << "Problem opening camera 1" << endl;

    if(!capture2.isOpened())  // check if we succeeded
        cout << "Problem opening camera 2" << endl;

    if(!capture3.isOpened())  // check if we succeeded
        cout << "Problem opening camera 3" << endl;

    int width = 1920;
    int height = 1080;

    capture0.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture0.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    capture1.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture1.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    capture2.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture2.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    capture3.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture3.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    //Mat edges;

    //Define compression parameters
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); // Save in Jpeg
    compression_params.push_back(95);// compression

    namedWindow("Camera 0",1);
    namedWindow("Camera 1",2);
    namedWindow("Camera 2",3);
    namedWindow("Camera 3",4);


    double wall1 = get_wall_time();//This is the time i need to manage the acquisition rate (fps).


    cout << "Wall Time = " << wall1 - wall0 <<" seconds" <<endl;

    int file = 0;
    string s = SSTR( file );
    cout << "s = " << s <<endl;
    wall0 = get_wall_time();
    float diff = 0;

    wall0 = get_wall_time();
    usleep(microseconds);
    cout << "Test usleep = " << get_wall_time() - wall0 <<" seconds" <<endl;

    for(;;)
    {
        s = SSTR( file );
        diff = get_wall_time() - wall0;
        //cout << "diff = " << diff << endl;
        if (diff > 0.75)
        {
            //Capture frame from camera0
            try{
                Mat frame0;
                capture0 >> frame0; // get a new frame from camera
                //imshow("Camera 0", frame0);
                bool saved = imwrite("./Camera0/test"+s+".jpg", frame0, compression_params);
                cout << "Image Saved from cam0= " << saved << endl;
                usleep(microseconds);
            }
            catch(...)
            {
                cout << "Problem capturing frame from Camera 0" << endl;
            }

            //Capture frame from camera1
            try{
                Mat frame1;
                capture1 >> frame1; // get a new frame from camera
                //imshow("Camera 1", frame1);
                bool saved = imwrite("./Camera1/test"+s+".jpg", frame1, compression_params);
                cout << "Image Saved from cam1= " << saved << endl;
                usleep(microseconds);
            }
            catch(...)
            {
                cout << "Problem capturing frame from Camera 1" << endl;
            }

            //Capture frame from camera2
            try{
                Mat frame2;
                capture2 >> frame2; // get a new frame from camera
                //imshow("Camera 2", frame2);
                bool saved = imwrite("./Camera2/test"+s+".jpg", frame2, compression_params);
                cout << "Image Saved from cam2= " << saved << endl;
                usleep(microseconds);

            }
            catch(...)
            {
                cout << "Problem capturing frame from Camera 2" << endl;
            }

            //Capture frame from camera3
            try{
                Mat frame3;
                capture3 >> frame3; // get a new frame from camera
                //imshow("Camera 3", frame3);
                bool saved = imwrite("./Camera3/test"+s+".jpg", frame3, compression_params);
                cout << "Image Saved from cam3= " << saved << endl;
                usleep(microseconds);
            }
            catch(...)
            {
                cout << "Problem capturing frame from Camera 3" << endl;
            }
            cout << "Time between pics = " << diff <<" seconds" <<endl;

            wall0 = get_wall_time();

        }

        if(waitKey(30) >= 0) break;

        file++;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
