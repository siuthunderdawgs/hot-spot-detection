#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getContourImg.h"
#include<iostream>

using namespace cv;


vector<vector<Point> > getContourImg(Mat src, vector<Vec4i> &hierarchy){


	vector<vector<Point> > contours;
	// double area;
	Scalar color(200); //color of contours in output image

	//!!!Median filter, erosion and dilation
	// blur( src, src, Size(2,2) );


    findContours( src, contours, hierarchy,
        CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

    // iterate through all the top-level contours,
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        drawContours( src, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    /*
    for(unsigned int i = 0; i < contours.size(); i++)
    {
		area = contourArea(contours[i]);
		std::cout << "Area" << i << "= " << area << std::endl;
	}
     */

    /* Show in a window
    namedWindow( "Contours", 2 );
    imshow( "Contours", src );
     */
    return contours;
}


