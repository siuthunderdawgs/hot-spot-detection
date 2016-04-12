/*
 * countContours.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: tygra
 */
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include<iostream>
#include"countContours.h"

using namespace cv;

bool countContours(vector<vector<Point> > &contours, vector<vector<Point> > &prev_contours, double &pix_thrsh_lowr, double &pix_thrsh_uppr)
{
	double area;
	vector<vector<Point> > new_contours;

	if(contours.size() == 0)
	{
		//std::cout<<"Zero contours in image: DONE"<<std::endl;
		contours = prev_contours;
		return true;
	}

	//Iterate through contours
	for(unsigned int i = 0; i < contours.size(); ++i)
	{
		area = contourArea(contours[i]);

		//Keep contours that are between lower and upper pixel threshold bounds
		if(area >= pix_thrsh_lowr)
		{
			new_contours.push_back(contours[i]);
			//std::cout << "Area" << i << "= " << area << std::endl;
		}
	}


	for(unsigned int i = 0; i < new_contours.size(); i++)
	{
		if(contourArea(new_contours[i])<= pix_thrsh_lowr || contourArea(new_contours[i]) >= pix_thrsh_uppr)
		{
			//std::cout << "Contour(s) out of pixel threshold range: NOT DONE\n";
			prev_contours = contours;
			return false;
		}
	}


	if(new_contours.size() > 1)
	{
		//std::cout << "Multiple contours in the image: NOT DONE\n";
		prev_contours = contours; // Make a copy of the previous contour vector
		return false; //Multiple contours in the image: NOT DONE
	}
	else if(new_contours.size() == 0)
	{
		//std::cout << "Use previous contour image: DONE\n";
		contours = prev_contours;
		return true; //Use previous contour vector: DONE
	}

	//std::cout << "Contour(s) in pixel threshold range: DONE\n";
	contours = new_contours;
	return true;
}


