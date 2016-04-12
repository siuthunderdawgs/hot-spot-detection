#include<iostream>
#include"hotSpotDetectionAlgorithm.h"

int main()
{
	// Read an image from directory and create Mat input
	const char* ir_image = "Images/Fabricated/f4.jpg";
	Mat input = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);

	if(input.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return 0;
	}

	// Local Variables
	Mat output = Mat::zeros( input.size(), CV_8U );
	Mat output_n_input;
	Mat tmp;
	vector<vector<Point> > contours;

	// Variable Assignment for Hot Spot Detection Algorithm
	int win_horz = 4;
	int win_vert = 4;
	double pix_thrsh_lowr = 3.0;
	double pix_thrsh_uppr = 50.0;
	double thresh_percent = 0.1;
	int blur_ksize = 3; // must be odd

	hotSpotDetectionAlgorithm(input, output, win_horz, win_vert, contours, thresh_percent, pix_thrsh_lowr, pix_thrsh_uppr, blur_ksize); //blur filter - getContourImg()

	// Input Image
	namedWindow("Input Image", 2);
	imshow("Input Image", input);

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
