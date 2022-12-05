#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void Camera()
{   
	// Open Camera Class 0 is index of camera (If multiple)
	VideoCapture cap = VideoCapture(0);

	Mat videoImage; //output image from video

	while (true)
	{
		cap.read(videoImage); //read image from video frame by frame
		imshow("Video", videoImage); //show image

		if (waitKey(1) == 122) //if pressed key 'z'
			break;
		
	}

	cap.release(); //close video
	destroyAllWindows(); //close all windows

}