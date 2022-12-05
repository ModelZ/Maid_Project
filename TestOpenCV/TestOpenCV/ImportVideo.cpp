#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void importVideo()
{
	// Import Video from path
	VideoCapture cap = VideoCapture("Video/song.mp4");

	Mat videoImage,grayVideoImage; //output image from video

	while (cap.isOpened())
	{
		bool check = cap.read(videoImage); //read image from video frame by frame
		
		cvtColor(videoImage, grayVideoImage, COLOR_BGR2GRAY); //convert color image to gray

		if (!check) // if video ended exit loop
			break;

		imshow("Video", grayVideoImage); //show gray image

		//imshow("Video", videoImage); //show image

		if (waitKey(1) == 122) //if pressed key 'z'
			break;

	}

	cap.release(); //close video
	destroyAllWindows(); //close all windows

}