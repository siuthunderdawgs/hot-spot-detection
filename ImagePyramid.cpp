#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


const int Width = 800;
const int Heigth = 600;



int main(int argc, char** argv)
{
	char* filename;
	filename = "../Pictures/test.jpg";

	cv::Mat src, dst, tmp;

	src = cv::imread(filename);

	tmp = src;
	dst = tmp;

	cv::namedWindow("Test Image Pyramid", CV_WINDOW_AUTOSIZE);
	cv::imshow("Test Image Pyramid", dst);

	return 0;
}
