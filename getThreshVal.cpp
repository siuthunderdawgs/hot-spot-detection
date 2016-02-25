/*
 * Intensity.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: tygra
 */
#include<iostream>
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getThreshVal.h"

using namespace cv;



int getThreshVal(Mat image, double Percentage)
{
    int pixel_count = 0;
    int threshold;


	// Allocate memory for no of pixels for each intensity value
	int histogram[256]={};


	// calculate the no of pixels for each intensity values
	for(int y = 0; y < image.rows; y++)
		for(int x = 0; x < image.cols; x++)
			histogram[(int)image.at<uchar>(y,x)]++;


	// find the maximum intensity element from histogram
	int max = histogram[0];
	for(int i = 1; i < 256; i++){
		if(max < histogram[i]){
			max = histogram[i];
		}
	}

	int pixels = image.rows*image.cols;

	//Find the initial threshold level based on top percentage of pixels.
	//Back iterate through histogram[], adding up the bins to find the bin that matches the desired percent.
	for( int i = 255; i>=0; i--)
	{
		pixel_count+=histogram[i];
		if((double)pixel_count/pixels >= Percentage)
		{
			threshold = i;
			break;
		}
	}

	// std::cout << "Threshold: " << threshold << endl;

	return threshold;

}
