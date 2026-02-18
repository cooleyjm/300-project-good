//Include Libraries
//OpenCV's cv::Mat acts like NumPy arrays for image processing.
 
#include<opencv2/opencv.hpp>
#include<iostream>


#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
    Mat image = imread("example.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) return -1;
 
    // Apply Gaussian blur
    Mat blurred;
    GaussianBlur(image, blurred, Size(0, 0), 2);
 
    // Apply Laplacian
    Mat laplacian;
    Laplacian(blurred, laplacian, CV_64F);
 
    // Convert to displayable format
    Mat result;
    convertScaleAbs(laplacian, result);
    imshow("LoG Blobs", result);
    imwrite("log_blobs.jpg", result);
 
    waitKey(0);
    return 0;
}



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
