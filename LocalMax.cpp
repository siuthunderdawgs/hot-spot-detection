/*
 * LocalMax.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: tygra
 */
#include <cv.h>
#include <highgui.h>
#include <imgproc/imgproc.hpp>
#include <highgui/highgui.hpp>
#include <photo/photo.hpp>

using namespace cv;

int main()
{
	/* Local Variables */
int squareSize = 3;
const char* ir_image = "./images/ir11.jpg";
Mat src = imread(ir_image, 0);
Mat dst;
char* winName1 = "Window 1";
char* winName2 = "Window 2";

//Normal Image
namedWindow(winName1, 0);
imshow(winName1, src);


if (squareSize==0)
{
    dst = src.clone();
    return -1;
}

Mat m0;
dst = src.clone();
Point maxLoc(0,0);

//Histogram Variables
const int channels = 1;
int dims = 1;
int histSize = 256;
int uniform = 1;
int nimages = 1;
float range[] = {0, 256};
const float* histRange = {range};
//Mat hist;

IplImage* im = cvLoadImage(ir_image, 0);

CvHistogram* hist = cvCreateHist(dims, &histSize, CV_HIST_ARRAY, NULL, uniform);
cvCalcHist(&im, hist);

//calcHist(&src, nimages, &channels, NULL, hist, dims, &histSize, &histRange, uniform, false);
 

//1.Be sure to have at least 3x3 for at least looking at 1 pixel close neighbours
//  Also the window must be <odd>x<odd>
//SANITYCHECK(squareSize,3,1);
int sqrCenter = (squareSize-1)/2;

//2.Create the localWindow mask to get things done faster
//  When we find a local maxima we will multiply the subwindow with this MASK
//  So that we will not search for those 0 values again and again
Mat localWindowMask = Mat::zeros(Size(squareSize,squareSize),CV_8U);//boolean
localWindowMask.at<unsigned char>(sqrCenter,sqrCenter)=1;

//3.Find the threshold value to threshold the image
    //this function here returns the peak of histogram of picture
    //the picture is a thresholded picture it will have a lot of zero values in it
    //so that the second boolean variable says :
    //  (boolean) ? "return peak even if it is at 0" : "return peak discarding 0"
float thrshld;
float min_value = 0;
cvGetMinMaxHistValue(hist, &min_value, &thrshld, NULL, NULL);
std::cout << "Threshold Value: " << thrshld << std::endl;

//maxUsedValInHistogramData(dst,false);
threshold(dst,m0,thrshld,1,THRESH_BINARY);

//4.Now delete all thresholded values from picture
dst = dst.mul(m0);

//put the src in the middle of the big array
for (int row=sqrCenter;row<dst.size().height-sqrCenter;row++)
    for (int col=sqrCenter;col<dst.size().width-sqrCenter;col++)
    {
        //1.if the value is zero it can not be a local maxima
        if (dst.at<unsigned char>(row,col)==0)
            continue;
        //2.the value at (row,col) is not 0 so it can be a local maxima point
        m0 =  dst.colRange(col-sqrCenter,col+sqrCenter+1).rowRange(row-sqrCenter,row+sqrCenter+1);
        minMaxLoc(m0,NULL,NULL,NULL,&maxLoc);
        //if the maximum location of this subWindow is at center
        //it means we found the local maxima
        //so we should delete the surrounding values which lies in the subWindow area
        //hence we will not try to find if a point is at localMaxima when already found a neighbour was
        if ((maxLoc.x==sqrCenter)&&(maxLoc.y==sqrCenter))
        {
            //m0 = m0.mul(localWindowMask);
                            //we can skip the values that we already made 0 by the above function
            col+=sqrCenter;
        }
    }

//Output Picture
namedWindow(winName2, 0);
imshow(winName2, dst);

while(true)
{
  int c;
  c = waitKey( 20 );
  if( (char)c == 27 )
    { break; }
 }
return 0;
}



