/*
 * countContours.h
 *
 *  Created on: Feb 22, 2016
 *      Author: tygra
 */

#ifndef COUNTCONTOURS_H_
#define COUNTCONTOURS_H_
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include<iostream>
#include"countContours.h"

using namespace cv;

bool countContours(vector<vector<Point> > &contours, vector<vector<Point> > &prev_contours, double &pixel_thresh);


#endif /* COUNTCONTOURS_H_ */
