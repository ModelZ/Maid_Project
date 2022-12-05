#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;


void Drawing()
{

	Mat img = imread("Image/kokomi.jpg");

	resize(img,img,{700,1000});

	// Draw a line
	// line(IMG, p1, p2, color {B,G,R}, thickness)
	line(img, {0,0}, {200,200}, {0, 255, 0}, 10);


	// Draw an arrowed line
	// arrowedLine(IMG, p1, p2, color {B,G,R}, thickness)
	arrowedLine(img, { 100,250 }, { 250,300 }, { 0, 0, 255 }, 10);


	// Draw a rectangle
	// rectangle(IMG, p1, p2, color {B,G,R}, thickness (-1 for fill))
	rectangle(img, { 50,50 }, {200,200}, {100,255,255}, 10);
	rectangle(img, { 50,100 }, { 100,150 }, { 100,100,255 }, -1);

	// Draw a circle
	// circle(IMG, centerPoint, radius, color {B,G,R}, thickness (-1 for fill))
	circle(img, {600,200}, 75, {100,200,200}, 5);

	// Write a Text
	// putText(IMG, msg, pos(x,y), font, size, color {B,G,R}, lineType)
	putText(img, "Kokomi", {175,700}, FONT_HERSHEY_SIMPLEX, 3, {0,255,0}, LINE_8);


	imshow("Image", img);

	waitKey(0);
	destroyAllWindows();


}