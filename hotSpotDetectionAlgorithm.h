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
#include"windows.h"

using namespace std;

void hotSpotDetectionAlgorithm(Mat &src, Mat &output, int win_horz, int win_vert, vector<vector<Point> > &contours, double &thresh_percent, double &pix_thrsh_lowr, double &pix_thrsh_uppr, int blur_ksize);



#endif /* HOTSPOTDETECTIONALGORITHM_H_ */
