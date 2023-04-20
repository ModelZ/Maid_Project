#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int cas()
{
	String imagePath = "Image/kokomi.jpg";

	Mat image = imread(imagePath, IMREAD_COLOR);

	cv::Size size(image.cols * 0.4, image.rows * 0.4);
	cv::resize(image, image, size, cv::INTER_AREA);

	double angle = 90.0;  // Rotation angle in degrees

	Point2f center(image.cols / 2.0, image.rows / 2.0);  // Center point of the image

	Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);  // Create a 2D rotation matrix

	Mat rotatedImg;

	warpAffine(image, rotatedImg, rotationMatrix, image.size());  // Apply the rotation

	imshow("Rotated image", rotatedImg);

	waitKey(0);

	return 0;
}