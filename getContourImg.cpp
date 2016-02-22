#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getContourImg.h"
#include<iostream>

using namespace cv;


vector<vector<Point> > getContourImg(Mat src){

	//Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	double area;
	Scalar color(200);

	blur( src, src, Size(2,2) );

	//This could be a robust solution, but a canny thresh is required.
	/*
	/// Detect edges using canny
	Canny( src, canny_output, thresh, thresh*2, 3 );
	*/

    findContours( src, contours, hierarchy,
        CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        //fillPoly(src, contours, hierarchy, );
        drawContours( src, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    for(unsigned int i = 0; i < contours.size(); i++)
    {
		area = contourArea(contours[i]);
		std::cout << "Area" << i << "= " << area << std::endl;
	}

    /// Show in a window
    namedWindow( "Contours", 2 );
    imshow( "Contours", src );

    return contours;
}


