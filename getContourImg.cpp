#include<highgui/highgui.hpp>
#include<imgproc/imgproc.hpp>
#include"getContourImg.h"
#include<iostream>

using namespace cv;


vector<vector<Point> > getContourImg(Mat input, vector<Vec4i> &hierarchy, int blur_ksize){


	vector<vector<Point> > contours;
	Scalar color(200); //color of contours in output image

	// blur the contours to avoid pixelated fragmentation.
	// warning: increasing the kernel size greatly affects the final outcome
	// warning: blur_ksize must be odd
	medianBlur(input, input, blur_ksize);


    findContours( input, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

    if(contours.size() == 0)
    {
    	return contours;
    }

    // iterate through all the top-level contours,
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        drawContours( input, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    return contours;
}


