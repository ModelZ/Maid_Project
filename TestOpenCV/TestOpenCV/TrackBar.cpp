#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

string type2str(int type) {
	string r;

	uchar depth = type & CV_MAT_DEPTH_MASK;
	uchar chans = 1 + (type >> CV_CN_SHIFT);

	switch (depth) {
	case CV_8U:  r = "8U"; break;
	case CV_8S:  r = "8S"; break;
	case CV_16U: r = "16U"; break;
	case CV_16S: r = "16S"; break;
	case CV_32S: r = "32S"; break;
	case CV_32F: r = "32F"; break;
	case CV_64F: r = "64F"; break;
	default:     r = "User"; break;
	}

	r += "C";
	r += (chans + '0');

	return r;
}

void display(int value,void *)
{
	cout << value << endl;
}

void TrackBar()
{
	//cout << type2str(16) << endl;

	Mat image{}; 
	image = Mat::zeros({ 300,350 }, CV_8UC3);

	namedWindow("Color Trackbar");

	//Create Trackbar
	createTrackbar("Blue", "Color Trackbar", 0, 255, display);
	createTrackbar("Green", "Color Trackbar", 0, 255, display);
	createTrackbar("Red", "Color Trackbar", 0, 255, display);

	while (true)
	{
		imshow("Color Trackbar", image);

		if (waitKey(1) == 122)
			break;

		//get value from trackbar
		int blue = getTrackbarPos("Blue", "Color Trackbar");
		int green = getTrackbarPos("Green", "Color Trackbar");
		int red = getTrackbarPos("Red", "Color Trackbar");

		image = image.setTo(Scalar(blue,green,red));


	}
	
	
	destroyAllWindows();

}