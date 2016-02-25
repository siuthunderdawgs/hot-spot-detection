#include<iostream>
#include"hotSpotDetectionAlgorithm.h"

int main()
{
	// Read an image from directory and create Mat src
	const char* ir_image = "Images/Fabricated/f3.jpg";
	Mat src = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst = src.clone();

	// Create contour vector for points
	vector<vector<Point> > contours;
	double pixel_thresh = 20.0;

	if(src.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return 0;
	}

	// Original Image
	namedWindow("Original Image", 2);
	imshow("Original Image", src);

	hotSpotDetectionAlgorithm(dst, contours, pixel_thresh); //blur filter - getContourImg()

	// Hot Spot Image
	namedWindow("Hot Spot Image", 2);
	imshow("Hot Spot Image", dst);

	waitKey(0);

	return 0;
}
