#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

void videoFaceDetect()
{
	// Import Video from path
	VideoCapture cap = VideoCapture("Video/Mark.mp4");

	Mat videoImage, grayVideoImage; //output image from video

	//Read File Image Classification
	CascadeClassifier face_cascade = CascadeClassifier("Detect/haarcascade_frontalface_default.xml");

	//Face Classification
	vector<Rect> faceDetect; // Vector of rectangles

	double scaleFactor = 1.3; // Parameter specifying how much the image size is reduced at each image scale.
	int minNeighbors = 5; // Parameter specifying how many neighbors each candidate rectangle should have to retain it.

	while (cap.isOpened())
	{
		bool check = cap.read(videoImage); //read image from video frame by frame

		//convert color image to gray
		cvtColor(videoImage, grayVideoImage, COLOR_BGR2GRAY);

		face_cascade.detectMultiScale(grayVideoImage, faceDetect, scaleFactor, minNeighbors);

		//Show face position found in rectangle form
		for (Rect found : faceDetect) {
			rectangle(videoImage, found, { 0,255,0 }, 5); 
			imshow("Video", videoImage); //show gray image
		}		

		if (!check) // if video ended exit loop
			break;

		if (waitKey(10) == 122) //if pressed key 'z'
			break;

	}

	cap.release(); //close video
	destroyAllWindows(); //close all windows

}