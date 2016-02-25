/*
 * hotSpotDetectionAlgorithm.h
 *
 *  Created on: Feb 25, 2016
 *      Author: tygra
 */

#ifndef HOTSPOTDETECTIONALGORITHM_H_
#define HOTSPOTDETECTIONALGORITHM_H_

#include<iostream>
#include"getThreshVal.h"
#include"getContourImg.h"
#include"countContours.h"
#include"hotSpotImage.h"
#include"hotSpotDetectionAlgorithm.h"

using namespace std;

void hotSpotDetectionAlgorithm(Mat &src, vector<vector<Point> > &contours, double &pixel_thresh);



#endif /* HOTSPOTDETECTIONALGORITHM_H_ */
