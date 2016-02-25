#include<iostream>
#include"getThreshVal.h"
#include"getContourImg.h"
#include"countContours.h"
#include"hotSpotImage.h"
#include"hotSpotDetectionAlgorithm.h"

using namespace std;

void hotSpotDetectionAlgorithm(Mat &src, vector<vector<Point> > &contours, double &pixel_thresh){


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
	Mat dst = Mat::zeros( src.size(), CV_8UC3 ); // Initialize empty Mat
	vector<Vec4i> hierarchy;
	//vector<vector<Point> > contours;
	vector<vector<Point> > prev_contours;
	char* winName1 = "Original Image";
	char* winName2 = "Threshold Image";
	char* winName3 = "Hot Spot Image";
	double Percentage = 0.10;
	bool count, check;
	int thrshld;
	// double pixel_thresh;

	/*Normal Image
	namedWindow(winName1, 2);
	imshow(winName1, src);
	 */

	/**********Background*********
	 * Reduce the percentage level through iteration. This will increase the
	 * threshold level, which will affect the number of contours in an image.
	 * The stopping condition of the loop must depend on the number of
	 * contours in an image. When there is one contour left in the image,
	 * the loop should break. This would indicate the "hottest spot" in the
	 * image.
	 *
	 * The returned value "contours" is a vector of
	 * vectors; rather, it is a vector that holds a set of points for each
	 * contour in the image. Example: if the vector has 3 containers, there
	 * are 3 contour shapes in the image.
	 *
	 * There are several different conditions that affect the number of
	 * contours in the image. For example, one threshold level may produce
	 * 5 contours and the next highest produce 12. Likewise, there are many
	 * different variable conditions that determine what a contour is (refer
	 * to getContourImg.cpp and the functions used).
	 */

    /***********What Needs to be Done*********
     *
     */

	/**********End Notes*********
	 * This isn't perfect. There are plenty of worst case scenarios this
	 * will fail on, but it should take care of the basic hot spots in
	 * generic images.
	 *
	 * This program will also always find a hot spot, even if it isn't a
	 * true hot spot, but that's where cross-examination with the other
	 * algorithms will help.
	 */

	check = true;
	pixel_thresh = 20; //Initiate minimum contour area

	while(true)
	{
		// Obtain threshold value and print value
		if(!check)
		{
			++thrshld;
			// std::cout << "Threshold: " << thrshld << std::endl;
		}
		else
		{
			thrshld = getThreshVal(tmp1, Percentage);
			// cout << "Initial Thresh: %" << Percentage*100 << endl;
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
		count = countContours(contours, prev_contours, pixel_thresh);
		if(count == true)
		{
			// cout << "\nDone!\n";
			break;
		}
	}

	// Produce the final output Mat
	hotSpotImage(dst, contours, pixel_thresh, hierarchy);

	// Output Mat dst (a.k.a. src)
	src = dst;

	/* Show hot spot image
	namedWindow(winName3, 2);
	imshow(winName3, dst);

	waitKey(0);
	*/
	// return 0;
}
