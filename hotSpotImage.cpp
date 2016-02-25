/*
 * hotSpotImage.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: tygra
 */
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include<iostream>
#include"hotSpotImage.h"

using namespace cv;


void hotSpotImage(Mat &src, vector<vector<Point> > &contours, double &pixel_thresh, vector<Vec4i> &hierarchy)
{

	if(src.empty())
	{
		std::cout << "Image not found. hotSpotImage(). Whoops?!\n";
		return;
	}

	double area;
	vector<vector<Point> > new_contours;
	Scalar color(255 , 255, 255); //color of contours in output image - using white

	// Iterate through contours
	for(unsigned int i = 0; i < contours.size(); ++i)
	{
		area = contourArea(contours[i]);

		// Ignore contours smaller than  pixel_thersh
		if(area >= pixel_thresh)
		{
			// std::cout << "Area" << i << "= " << area << std::endl;
			new_contours.push_back(contours[i]);
		}
	}

    // iterate through all the top-level contours
	// produces a black image with white blobs (i.e. contours)
	for( unsigned int i = 0; i< new_contours.size(); i++ )
	 {
		drawContours( src, new_contours, i, color, CV_FILLED, 8, hierarchy, 0, Point() );
	 }

	contours = new_contours;
}



