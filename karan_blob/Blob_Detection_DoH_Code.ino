//Include Libraries
//OpenCV's cv::Mat acts like NumPy arrays for image processing.
//WANTS TO IMPORT OPEN CV LIBRARIES

#include<opencv2/opencv.hpp>
#include<iostream>

//BLOB DETECTION USING DETERMINANT OF HESSIAN METHOD:
void setup() {
  // put your setup code here, to run once:
    //NOT SURE IF THIS GOES HERE
    //ADD THE DATA READINGS FROM IR SENSOR + PIN OUT
    #include <opencv2/opencv.hpp>
    using namespace cv;
    int main() {
        Mat image = imread("example.jpg", IMREAD_GRAYSCALE);//COMPUTATION FOR IR SENSOR GOES HERE?
        if (image.empty()) 
          return -1;
    
        // Compute second-order derivatives
        Mat dxx, dyy, dxy;
        Sobel(image, dxx, CV_64F, 2, 0);
        Sobel(image, dyy, CV_64F, 0, 2);
        Sobel(image, dxy, CV_64F, 1, 1);
    
        // Determinant of Hessian
        Mat hessianDet = dxx.mul(dyy) - dxy.mul(dxy);
    
        // Normalize and convert to displayable format
        Mat result;
        normalize(hessianDet, result, 0, 255, NORM_MINMAX);
        result.convertTo(result, CV_8U);
        imshow("DoH Blobs", result);
        imwrite("doh_blobs.jpg", result);
    
        waitKey(0);
        return 0;
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
