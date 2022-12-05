#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;



void DetectObject()
{
	String imagePath = "Image/kokomi.jpg";

	while (true)
	{
		Mat image = imread(imagePath, IMREAD_COLOR);

		resize(image, image, { 700,900 });

		// Color Range
		InputArray lower = Scalar(134,126,191);
		InputArray upper = Scalar(237,249,255);

		Mat mask,result;
		inRange(image, lower, upper, mask); //create mask

		bitwise_and(image, image, result, mask); //combine color to mask

		imshow("Image", image);
		imshow("Mask", mask);
		imshow("Result", result);

		if (waitKey(1) == 122)
			break;
	}

	cv::destroyAllWindows();

}