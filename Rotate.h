#ifndef ROT_H
#define ROT_H

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

 
using namespace std;
using namespace cv;

class Rotate
{
private:
	Mat m_image;
	Mat m_rotated;
	double m_angle;
public:
	Rotate(Mat image)
	{
		m_image = image;
	}
	void rot()
	{
		for (int j = 0; j < 10; j++)
			waitKey(1);
		imshow("The Initial Image", m_image);
		cout << "To continue press any key when your cursor are in the area of the opened window with image" << endl;
		waitKey(0);
		cout << "\nPlease, input the angle to wich you woud like to rotate image: ";
		cin >> m_angle;
		cout << "\n";
		Mat rot = getRotationMatrix2D(Point2f(static_cast<int>(m_image.cols / 2), static_cast<int>(m_image.rows / 2)), m_angle, 1);
		warpAffine(m_image, m_rotated, rot, m_image.size());
		for(int j=0; j<10;j++)
			waitKey(1);
		imshow("The Rotated Image", m_rotated);
		cout << "To continue press any key when your cursor are in the area of opened windows with images" << endl;
		waitKey(0);
	}
	Mat getRotated() { return m_rotated; }
};

#endif
