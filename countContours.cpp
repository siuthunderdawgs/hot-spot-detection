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
		std::cout<<"Zero contours in image: DONE"<<std::endl;
		return true;
	}

	//Iterate through contours
	for(unsigned int i = 0; i < contours.size(); ++i)
	{
		area = contourArea(contours[i]);

		//Keep contours that are between lower and upper pixel threshold bounds
		if((area >= pix_thrsh_lowr) && (area <= pix_thrsh_uppr))
		{
			new_contours.push_back(contours[i]);
			std::cout << "Area" << i << "= " << area << std::endl;
		}
	}

	if(new_contours.size() > 1)
	{
		std::cout << "Multiple contours in the image: NOT DONE\n";
		prev_contours = contours; // Make a copy of the previous contour vector
		return false; //Multiple contours in the image: NOT DONE
	}
	else if(new_contours.size() == 0)
	{
		std::cout << "Use previous contour vector: DONE\n";
		contours = prev_contours;
		return true; //Use previous contour vector: DONE
	}
	else if(new_contours.size() == 1)
	{
		std::cout << "1 desirable contours in the vector: DONE\n";
		contours = new_contours;
		return true; //1 desirable contours in the vector: DONE
	}
	else
	{
		std::cout << "countContours() - Whoops?!\n";
		return false;
	}
}


