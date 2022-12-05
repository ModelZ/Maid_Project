#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void testOpenCV()
{   
    string imagePath = "Image/kokomi.jpg";

    Mat image = imread(imagePath,IMREAD_GRAYSCALE);

    resize(image, image, {600,600});

    imshow("Image", image); //show image

    waitKey(5000); //delay 5 secs

    imwrite("Kokomi_gray.jpg", image);

    destroyAllWindows(); //Close image window

}

