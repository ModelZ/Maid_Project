#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

void imageFaceDetect()
{
	String imagePath = "Image/BLACKPINK.jpg";
	Mat image = imread(imagePath, IMREAD_COLOR);

	//Read File Image Classification
	CascadeClassifier face_cascade = CascadeClassifier("Detect/haarcascade_frontalface_default.xml");

	//Convert Image to gray image
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	//Face Classification

	vector<Rect> faceDetect; // Vector of rectangles

	double scaleFactor = 1.1; // Parameter specifying how much the image size is reduced at each image scale.
	int minNeighbors = 3; // Parameter specifying how many neighbors each candidate rectangle should have to retain it.

	face_cascade.detectMultiScale(grayImage,faceDetect,scaleFactor,minNeighbors); 

	//Show face position found in rectangle form
	for (Rect found : faceDetect)
		rectangle(image, found, { 0,255,0 }, 5);

	imshow("Output",image);

	waitKey(0);

	destroyAllWindows();

}