#include<iostream>
#include"getThreshVal.h"
#include"getContourImg.h"
#include"countContours.h"
#include"hotSpotImage.h"
#include"hotSpotDetectionAlgorithm.h"
#include"windows.h"

using namespace std;

void hotSpotDetectionAlgorithm(Mat &input, Mat &output, int win_horz, int win_vert, vector<vector<Point> > &contours, double &thresh_percent,  double &pix_thrsh_lowr, double &pix_thrsh_uppr, int blur_ksize){

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

	if(countNonZero(output) != 0 || output.empty())
	{
		std::cout << "Mat &output must be: Mat::zeros( input.size(), CV_8U )\n";
		return;
	}

	vector<vector<Mat> > windows_in;
	vector<vector<Mat> > windows_out;

	windows_in = CreateWindows(input, win_horz, win_vert);
	windows_out = CreateWindows(output, win_horz, win_vert);

	for(int col = 0; col < win_vert; ++col)
	{
		for(int row = 0; row < win_horz; ++row)
		{

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
					//std::cout << "Threshold: " << thrshld << std::endl;
				}
				else
				{
					thrshld = getThreshVal(windows_in[row][col], thresh_percent);
					//cout << "Initial Thresh: %" << thresh_percent*100 << endl;
					//cout << "Threshold: " << thrshld << endl;
					check = false;
				}

				threshold(windows_in[row][col],output_contour,thrshld, 255, THRESH_BINARY);

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
			hotSpotImage(windows_out[row][col], contours, pix_thrsh_lowr, pix_thrsh_uppr, hierarchy);
		}
	}
}
