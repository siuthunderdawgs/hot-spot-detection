#include<iostream>
#include"getThreshVal.h"
#include"getContourImg.h"
#include"countContours.h"
#include"hotSpotImage.h"
#include"hotSpotDetectionAlgorithm.h"

using namespace std;

/* Update
/*
 * Add and input/output parameter to the function (Mat input, Mat output)
 *
 * Include all possible parameters, use defaults, or make everything a class
 *
 * Mat input is being cloned and losing the pointers for the Windows() function.
 *
 * Pass input into hotSpotImage()??
 */

void hotSpotDetectionAlgorithm(Mat &input, Mat &output, vector<vector<Point> > &contours, double &thresh_percent,  double &pix_thrsh_lowr, double &pix_thrsh_uppr, int blur_ksize){

	if(input.empty())
	{
		std::cout << "No Input Image - hotSpotDetectionAlgorithm().\n";
		return;
	}

	if((blur_ksize % 2) == 0)
	{
		std::cout << "blur_ksize must be odd for medianBlur() - hotSpotDetectionAlgorithm()\n";
		return;
	}

	/* Local Variables */

	Mat output_contour;
	vector<Vec4i> hierarchy;
	vector<vector<Point> > prev_contours;
	bool count, check;
	int thrshld;

	check = true;

	while(true)
	{
		// Obtain threshold value and print value
		if(!check)
		{
			++thrshld;
			std::cout << "Threshold: " << thrshld << std::endl;
		}
		else
		{
			thrshld = getThreshVal(input, thresh_percent);
			cout << "Initial Thresh: %" << thresh_percent*100 << endl;
			cout << "Threshold: " << thrshld << endl;
			check = false;
		}

		threshold(input,output_contour,thrshld, 255, THRESH_BINARY);

		// Get the vector of contours and print contour images
		contours = getContourImg(output_contour, hierarchy, blur_ksize);

		// Find number of contours in image
		count = countContours(contours, prev_contours,  pix_thrsh_lowr, pix_thrsh_uppr);
		if(count == true)
		{
			break;
		}
	}

	// Produce the final output Mat
	hotSpotImage(output, contours, pix_thrsh_lowr, pix_thrsh_uppr, hierarchy);
}
