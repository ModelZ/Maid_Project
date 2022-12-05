#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <ctime>

using namespace std;
using namespace cv;

void dateTimeVideo()
{
	// Import Video from path
	//VideoCapture cap = VideoCapture("Video/song.mp4");
	VideoCapture cap = VideoCapture(0);

	Mat videoImage; //output image from video

	while (cap.isOpened())
	{
		// current date/time based on current system
		time_t now = time(NULL);

		// convert now to string form
		char str[26] = {};
		ctime_s(str, 26, &now);
		

		bool check = cap.read(videoImage); //read image from video frame by frame

		if (!check) // if video ended exit loop
			break;

		putText(videoImage, str, { 10,50 }, FONT_HERSHEY_SIMPLEX, 2, { 200,255,100 }, LINE_4);

		imshow("Video", videoImage); //show image

		if (waitKey(1) == 122) //if pressed key 'z'
			break;

	}

	cap.release(); //close video
	destroyAllWindows(); //close all windows


}