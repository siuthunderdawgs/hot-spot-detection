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

	/**********Background*********
	 * Reduce the percentage level through iteration. This will increase the
	 * threshold level, which will affect the number of contours in an image.
	 * The stopping condition of the loop must depend on the number of
	 * contours in an image. When there is one contour left in the image,
	 * the loop should break. This would indicate the "hottest spot" in the
	 * image.
	 *
	 * The returned value "contours" is a vector of
	 * vectors; rather, it is a vector that holds a set of points for each
	 * contour in the image. Example: if the vector has 3 containers, there
	 * are 3 contour shapes in the image.
	 *
	 * There are several different conditions that affect the number of
	 * contours in the image. For example, one threshold level may produce
	 * 5 contours and the next highest produce 12. Likewise, there are many
	 * different variable conditions that determine what a contour is (refer
	 * to getContourImg.cpp and the functions used).
	 */

    /***********What Needs to be Done*********
	 * 1. Find the stopping condition for the loop. (May need a different
	 *    kind of loop)
	 *
	 * 2. Need a function to pass in "contours" to determine the number
	 *    of contours in the image. Not sure what it should return.
	 *
	 * 3. The entire algorithm should be able to work with a windowing
	 *    function to find all possible hot spots in an image.
	 */

	/**********End Notes*********
	 * This isn't perfect. There are plenty of worst case scenarios this
	 * will fail on, but it should take care of the basic hot spots in
	 * generic images.
	 *
	 * This program will also always find a hot spot, even if it isn't a
	 * true hot spot, but that's where cross-examination with the other
	 * algorithms will help.
	 */

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
