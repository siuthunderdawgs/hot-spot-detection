#include <cv.h>
#include <highgui.h>

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


const int Width = 800;
const int Heigth = 600;



int main(int argc, char** argv)
{
	char* filename;
	filename = "test.jpg";

	cv::Mat src, dst, tmp;

	src = cv::imread(argv[1], 1);

	tmp = src;
	dst = tmp;

	cv::namedWindow("Test Image Pyramid", CV_WINDOW_AUTOSIZE);
	cv::imshow("Test Image Pyramid", dst);

	cv::waitKey(0);

	std::cout<< "Help";
	return 0;
}
