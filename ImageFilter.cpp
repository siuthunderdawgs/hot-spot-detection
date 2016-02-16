#include <cv.h>
#include <highgui.h>
#include <photo/photo.hpp>
#include <imgproc/imgproc.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace cv;

int main(int argc, char** argv)
{

	int tempSize, searchSize, threshold_value;
	float h=9;
	tempSize = 7;
	searchSize = 15;
	threshold_value = 50;

	string filename;
	filename = "./Images/ir3.jpg";

	Mat src, dst, tmp;
	src = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

	if(src.empty())
	{
		std::cout<<"Failed Image Read: Image not Found."<<std::endl;
	}

	namedWindow("Test Thermal Image", CV_WINDOW_AUTOSIZE);
	imshow("Test Thermal Image", src);



	fastNlMeansDenoising(src, tmp, h, tempSize, searchSize );
	//threshold( tmp, dst, threshold_value, max_BINARY_value,threshold_type );
	namedWindow("Test Filter", CV_WINDOW_AUTOSIZE);
	imshow("Test Filter", dst);


	waitKey(0);

	return 0;
}

