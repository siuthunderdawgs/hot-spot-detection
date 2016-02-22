/*
 * LocalMax.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: tygra
 */
#include <cv.h>
#include <highgui.h>
#include <imgproc/imgproc.hpp>
#include <highgui/highgui.hpp>
#include <photo/photo.hpp>
#include<iostream>
#include "IntensityValue.h"

using namespace cv;
using namespace std;

int main()
{
	/* Local Variables */
	const char* ir_image = "images/ir2.jpg";
	Mat src = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst, tmp;
	char* winName1 = "Original Image";
	char* winName2 = "Threshold Image";

	//Normal Image
	namedWindow(winName1, 0);
	imshow(winName1, src);

	/*Obtain threshold value from intensityValue()*/
	int thrshld = intensityValue(tmp);
	threshold(tmp,dst,thrshld,1,THRESH_BINARY);

	//Output Picture
	namedWindow(winName2, 0);
	imshow(winName2, dst);

	while(true)
	{
	  int c;
	  c = waitKey( 20 );
	  if( (char)c == 27 )
		{ break; }
	 }

	return 0;
}



