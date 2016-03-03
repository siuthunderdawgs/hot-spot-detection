#include<iostream>
#include"hotSpotDetectionAlgorithm.h"
#include"windows.h"

int main()
{
	// Read an image from directory and create Mat src
	const char* ir_image = "Images/Fabricated/f3.jpg";
	Mat src = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst = Mat::zeros( src.size(), CV_8U );;
	Mat dst_n_src;
	vector<vector<Mat> > windows;
	int horz = 2;
	int vert = 2;

	// Create contour vector for points
	vector<vector<Point> > contours;
	double pix_thrsh_lowr = 8.0;
	double pix_thrsh_uppr = 100.0;
	double thresh_percent = 0.20;

	if(src.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return 0;
	}

	// Original Image
	namedWindow("Original Image", 2);
	imshow("Original Image", src);

	windows = CreateWindows(src, horz, vert);

	for(int col = 0; col < vert; ++col)
	{
		for(int row = 0; row < horz; ++row)
		{
			hotSpotDetectionAlgorithm(windows[col][row], contours, thresh_percent, pix_thrsh_lowr, pix_thrsh_uppr); //blur filter - getContourImg()
		}
	}


	// Windows
	namedWindow("windows[0][0]", 2);
	imshow("windows[0][0]", windows[0][0]);

	// Hot Spot Image
	namedWindow("Hot Spot Image", 2);
	imshow("Hot Spot Image", src);

	// Overlay Image
	Mat tmp;
	cvtColor(src, tmp, CV_GRAY2BGR);
	src = tmp.clone();
	cvtColor(dst, tmp, CV_GRAY2BGR);
	dst = tmp.clone();
	addWeighted(src, 1, dst, 0.5, 0, dst_n_src);
	namedWindow("Overlay Image", 2);
	imshow("Overlay Image", dst_n_src);

	waitKey(0);

	return 0;
}
