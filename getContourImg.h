/*
 * getContourImg.h
 *
 *  Created on: Feb 21, 2016
 *      Author: tygra
 */

#ifndef GETCONTOURIMG_H_
#define GETCONTOURIMG_H_

#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getContourImg.h"
#include<iostream>

using namespace cv;


vector<vector<Point> > getContourImg(Mat src, vector<Vec4i> &hierarchy);



#endif /* GETCONTOURIMG_H_ */
