/*
 * HotSpotContours.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: Tyler Betzler
 */
#include <cv.h>
#include <highgui.h>


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main(int argc, char** argv)
{
	char* filename;
	filename = "thermal.jpg";

	Mat src, dst, canny_output, contour_mat;

	src = imread(filename, 1);



	//namedWindow("Test Thermal Image", CV_WINDOW_AUTOSIZE);
	//imshow("Test Thermal Image", src);



	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	findContours(src, contour_mat, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", contour_mat);

	waitKey(0);
	return 0;
}


