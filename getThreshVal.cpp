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



int getThreshVal(Mat input, double Percentage)
{
    int pixel_count = 0;
    int threshold;


	// Allocate memory for number of pixels for each intensity value
	int histogram[256]={};


	// calculate the number of pixels for each intensity values
	for(int y = 0; y < input.rows; y++)
		for(int x = 0; x < input.cols; x++)
			histogram[(int)input.at<uchar>(y,x)]++;


	// find the maximum intensity element from histogram
	int max = histogram[0];
	for(int i = 1; i < 256; i++){
		if(max < histogram[i]){
			max = histogram[i];
		}
	}

	int pixels = input.rows*input.cols;

	// Find the initial threshold level based on top percentage of pixels.
	// Back iterate through histogram[], adding up the bins to find the bin that matches the desired percent.
	for( int i = 255; i>=0; i--)
	{
		pixel_count+=histogram[i];
		if((double)pixel_count/pixels >= Percentage)
		{
			threshold = i;
			break;
		}
	}

	return threshold;

}
