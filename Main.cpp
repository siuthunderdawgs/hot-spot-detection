#include<iostream>
#include"getThreshVal.h"
#include"getContourImg.h"

using namespace std;

int main(){

	/* Local Variables */
	//Images/Fabricated/f1.jpg
	//Images/Fabricated/f2.jpg
	const char* ir_image = "Images/Fabricated/f2.jpg";
	Mat src = imread(ir_image, CV_LOAD_IMAGE_GRAYSCALE);

	if(src.empty())
	{
		std::cout << "Image not found. Check directory.\n";
		return -1;
	}

	Mat dst, dst_contour;
	Mat tmp1 = src.clone();
	vector<vector<Point> > contours;
	char* winName1 = "Original Image";
	char* winName2 = "Threshold Image";
	char* winName3 = "Contour Image";
	double Percentage = 0.10;

	//Normal Image
	namedWindow(winName1, 2);
	imshow(winName1, src);

	while(Percentage >= 0.001)
	{
		//Obtain threshold value
		int thrshld = getThreshVal(tmp1, Percentage);
		threshold(tmp1,dst_contour,thrshld, 255, THRESH_BINARY);

		//Show threshold image
		namedWindow(winName2, 2);
		imshow(winName2, dst_contour);

		//Get the vector of contours and print contour images
		contours = getContourImg(dst_contour);

		Percentage = Percentage - 0.001;
	}
	//Output Picture
	//namedWindow(winName3, 2);
	//imshow(winName3, dst);

	while(true)
	{
	  int c;
	  c = waitKey( 20 );
	  if( (char)c == 27 )
		{ break; }
	 }
	return 0;
}
