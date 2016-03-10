/*
 * getThreshVal.h
 *
 *  Created on: Feb 20, 2016
 *      Author: tygra
 */

#ifndef GETTHRESHVAL_H_
#define GETTHRESHVAL_H_

#include<iostream>
#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getThreshVal.h"

using namespace std;
using namespace cv;



int getThreshVal(Mat input, double Percentage);



#endif /* GETTHRESHVAL_H_ */
