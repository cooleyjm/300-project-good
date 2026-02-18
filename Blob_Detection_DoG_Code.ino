//Include Libraries
//OpenCV's cv::Mat acts like NumPy arrays for image processing.
 
#include<opencv2/opencv.hpp>
#include<iostream>


#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
    Mat image = imread("example.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) return -1;
 
    // Apply two Gaussian blurs with different sigmas
    Mat g1, g2, dog;
    GaussianBlur(image, g1, Size(0, 0), 1);
    GaussianBlur(image, g2, Size(0, 0), 2);
 
    // Subtract to get DoG
    subtract(g1, g2, dog);
 
    // Convert to displayable format
    Mat result;
    normalize(dog, result, 0, 255, NORM_MINMAX);
    result.convertTo(result, CV_8U);
    imshow("DoG Blobs", result);
    imwrite("dog_blobs.jpg", result);
 
    waitKey(0);
    return 0;
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
