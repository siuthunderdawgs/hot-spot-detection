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
 * Mat src is being cloned and losing the pointers for the Windows() function.
 *
 * Pass src into hotSpotImage()??
 */

void hotSpotDetectionAlgorithm(Mat &src, vector<vector<Point> > &contours, double &thresh_percent,  double &pix_thrsh_lowr, double &pix_thrsh_uppr){


	//const char* ir_image = "Images/Fabricated/f3.jpg";
	//Mat src = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);

	if(src.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return;
	}

	/* Local Variables */

	Mat dst_contour;
	Mat tmp1 = src.clone();
	Mat dst = Mat::zeros( src.size(), CV_8U ); // Initialize empty Mat
	vector<Vec4i> hierarchy;
	//vector<vector<Point> > contours;
	vector<vector<Point> > prev_contours;
	//char* winName1 = "Original Image";
	//char* winName2 = "Threshold Image";
	//char* winName3 = "Hot Spot Image";
	//double thresh_percent = 0.10;
	bool count, check;
	int thrshld;
	// double pixel_thresh;

	/*Normal Image
	namedWindow(winName1, 2);
	imshow(winName1, src);
	 */


	check = true;
	//thresh_percent = 0.10;
	//pixel_thresh = 20; //Initiate minimum contour area

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
			thrshld = getThreshVal(tmp1, thresh_percent);
			cout << "Initial Thresh: %" << thresh_percent*100 << endl;
			cout << "Threshold: " << thrshld << endl;
			check = false;
		}

		threshold(tmp1,dst_contour,thrshld, 255, THRESH_BINARY);

		/* Show threshold image
		namedWindow(winName2, 2);
		imshow(winName2, dst_contour);
		 */

		// Get the vector of contours and print contour images
		contours = getContourImg(dst_contour, hierarchy);

		// Find number of contours in image
		count = countContours(contours, prev_contours,  pix_thrsh_lowr, pix_thrsh_uppr);
		if(count == true)
		{
			// cout << "\nDone!\n";
			break;
		}
	}

	// Produce the final output Mat
	hotSpotImage(dst, contours, pix_thrsh_lowr, pix_thrsh_uppr, hierarchy);

	// Output Mat dst (a.k.a. src)
	src = dst.clone();

	/* Show hot spot image
	namedWindow(winName3, 2);
	imshow(winName3, dst);

	waitKey(0);
	*/
	// return 0;
}
