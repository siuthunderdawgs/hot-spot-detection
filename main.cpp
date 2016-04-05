#include<iostream>
#include"hotSpotDetectionAlgorithm.h"
#include"windows.h"

int main()
{
	// Read an image from directory and create Mat input
	const char* ir_image = "Images/Fabricated/f3.jpg";
	Mat input = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);


	Mat output = Mat::zeros( input.size(), CV_8U );
	Mat output_n_input;
	Mat tmp;
	vector<vector<Mat> > windows_in;
	vector<vector<Mat> > windows_out;
	int horz = 2;
	int vert = 2;

	// Create contour vector for points
	vector<vector<Point> > contours;
	double pix_thrsh_lowr = 6.0;
	double pix_thrsh_uppr = 100.0;
	double thresh_percent = 0.05;
	int blur_ksize = 3; // must be odd

	if(input.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return 0;
	}

	// Input Image
	namedWindow("Input Image", 2);
	imshow("Input Image", input);

	// Window the input image and empty output image
	windows_in = CreateWindows(input, horz, vert);
	windows_out = CreateWindows(output, horz, vert);

	// Iterate through Hot Spot Algorithm using the windows
	for(int col = 0; col < vert; ++col)
	{
		for(int row = 0; row < horz; ++row)
		{
			std::cout << "window[" << row << "][" << col << "]\n";
			hotSpotDetectionAlgorithm(windows_in[row][col], windows_out[row][col], contours, thresh_percent, pix_thrsh_lowr, pix_thrsh_uppr, blur_ksize); //blur filter - getContourImg()
		}
	}

	// Hot Spot Image
	namedWindow("Hot Spot Image", 2);
	imshow("Hot Spot Image", output);

	// Overlay Image of Input and Output
	cvtColor(input, tmp, CV_GRAY2BGR);
	input = tmp.clone();
	cvtColor(output, tmp, CV_GRAY2BGR);
	output = tmp.clone();
	addWeighted(input, 1, output, 0.5, 0, output_n_input);
	namedWindow("Overlay Image", 2);
	imshow("Overlay Image", output_n_input);

	waitKey(0);

	return 0;
}
