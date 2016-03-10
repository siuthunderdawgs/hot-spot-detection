/*
 * hotSpotImage.h
 *
 *  Created on: Feb 25, 2016
 *      Author: tygra
 */

#ifndef HOTSPOTIMAGE_H_
#define HOTSPOTIMAGE_H_

#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include<iostream>
#include"hotSpotImage.h"

using namespace cv;


void hotSpotImage(Mat &output, vector<vector<Point> > &contours, double &pix_thrsh_lowr, double &pix_thrsh_uppr, vector<Vec4i> &hierarchy);



#endif /* HOTSPOTIMAGE_H_ */
