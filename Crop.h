#ifndef CROP_H
#define CROP_H
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

class Crop
{
private:
	Mat m_image;
	Mat m_crop;
	Point2f m_loc;
	Size m_size_crop;
public:
	Crop(Mat image)
	{
		m_image = image;
	}
	void input();
	void check_loc();
	void crop();
	Mat getCropImage() { return m_crop; }

};

#endif
