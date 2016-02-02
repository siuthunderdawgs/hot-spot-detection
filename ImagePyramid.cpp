#include <cv.h>
#include <highgui.h>

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


const int Width = 800;
const int Heigth = 600;

using namespace cv;

int main(int argc, char** argv)
{
	int col_mult, row_mult;

	char* filename;
	filename = "test.jpg";

	Mat src, dst, tmp;

	src = imread(argv[1], 1);

	int col_size = src.cols;
	int row_size = src.rows;

	std::cout<<col_size<<std::endl;
	std::cout<<row_size<<std::endl;
	tmp = src;
	dst = tmp;




	namedWindow("Test Image Pyramid", CV_WINDOW_AUTOSIZE);
	imshow("Test Image Pyramid", dst);

	waitKey(0);

	std::cout<< "Help";
	return 0;
}
