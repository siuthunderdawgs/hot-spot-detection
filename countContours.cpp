/*
 * countContours.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: tygra
 */
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"countContours.h"

using namespace cv;

unsigned int countContours(vector<vector<Point> > contours)
{
	double area;
	double pixel_thresh = 8.0; //8 seems reasonable for now
	vector<double> new_contours;

	if(contours.size() == 1)
	{
		return 1; //1 contour in the image
	}
	else
	{
		//Iterate through contours
	    for(unsigned int i = 0; i < contours.size(); ++i)
	    {
			area = contourArea(contours[i]);

			//Ignore contours smaller than  pixel_thersh
			if(area >= pixel_thresh)
				new_contours.push_back(i);
		}

	    if(new_contours.size() != 1)
	    	return 0; //More than 1 desirable contour in the image
	    else
	    	return 1; //1 desirable contour in the image
	}

}


