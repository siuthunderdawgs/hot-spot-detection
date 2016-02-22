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
#include"countContours.h"

using namespace cv;

unsigned int countContours(vector<vector<Point> > contours);


#endif /* COUNTCONTOURS_H_ */
