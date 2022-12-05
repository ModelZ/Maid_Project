#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void RecordVideo()
{
	// Open Camera Class 0 is index of camera (If multiple)
	VideoCapture cap = VideoCapture(0);
	
	Mat videoImage; //output image from video

	//Video Recorder Configuration
	VideoWriter record;
	int fourccCodec = VideoWriter::fourcc('X', 'V', 'I', 'D'); // codex for window
	double fps = 25.0;
	string filename = "output.mp4";

	//Initialize Recorder
	record.open(filename, fourccCodec, fps, {640,480});

	//check if ok
	if (!record.isOpened()) {
		cerr << "Could not open the output video file for write\n";
		exit(-1);
	}

	while (true)
	{
		cap.read(videoImage); //read image from video frame by frame

		record.write(videoImage); // encode the frame into the videofile stream

		imshow("Video", videoImage); //show image

		if (waitKey(1) == 122) //if pressed key 'z' exit loop
			break;

	}

	record.release(); //close recorder
	cap.release(); //close video
	destroyAllWindows(); //close all windows

}