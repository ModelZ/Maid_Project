#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

string imagePath = "Image/kokomi.jpg";

Mat image = imread(imagePath, IMREAD_COLOR);


void clickPosition(int event, int x, int y, int flags, void*) {
    if (event == EVENT_LBUTTONDOWN) {
        string text = to_string(x) + "," + to_string(y);
        putText(image, text, {x,y}, FONT_HERSHEY_SIMPLEX, 1, {0,0,255},3);
        imshow("Image", image);
    }
}

void clickColorBGR(int event, int x, int y, int flags, void*) {
    if (event == EVENT_LBUTTONDOWN) {

        //color channels
        int blue = image.at<Vec3b>(y, x)[0];
        int green = image.at<Vec3b>(y, x)[1];
        int red = image.at<Vec3b>(y, x)[2];

        string text = to_string(blue) + "," + to_string(green) + "," + to_string(red);
        putText(image, text, { x,y }, FONT_HERSHEY_SIMPLEX, 1, { 0,0,255 }, 3);
        imshow("Image", image);
    }
}

void clickColorNewWindow(int event, int x, int y, int flags, void*) {
    if (event == EVENT_LBUTTONDOWN) {

        //color channels
        int blue = image.at<Vec3b>(y, x)[0];
        int green = image.at<Vec3b>(y, x)[1];
        int red = image.at<Vec3b>(y, x)[2];

        Mat color = Mat::zeros(300,300,image.type()); //create new Mat with all filled with zero

        color = color.setTo(Scalar(blue,green,red)); //Turn image to specific color

        string text = "RGB(" + to_string(red) + "," + to_string(green) + "," + to_string(blue)+ ")";
        putText(color, text, { 0,25 }, FONT_HERSHEY_SIMPLEX, 0.85, { 0,0,0 }, 2);

        imshow("Color", color);
    }
}


vector<Point> point = {}; //List of Point when clicked

void printPoint(vector<Point>& container)
{
    cout << "{";
    for (int i = 0; i < container.size(); i++) {
        cout << container.at(i);
        if(i != container.size() - 1)
            cout << ", ";
    }
        
    cout << "}\n";
}

void clickConnectPoint(int event, int x, int y, int flags, void*) {
 

    if (event == EVENT_LBUTTONDOWN) {

        circle(image, { x,y }, 10, { 0,0,255 }, 4);

        point.insert(point.begin(), { x,y }); // Add clicked point in List

        if (point.size() >= 2)
            line(image, point[0], point[1], { 0,255,0 }, 5);

        printPoint(point); //print out all points

        imshow("Image", image);

    }
}

void MouseEvent ()
{

    resize(image, image, { 700,900 });

    imshow("Image", image); //show image
    setMouseCallback("Image", clickConnectPoint);

    waitKey(0);
    destroyAllWindows(); //Close image window

}

