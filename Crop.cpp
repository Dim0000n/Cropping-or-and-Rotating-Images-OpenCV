#include "Crop.h"

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;

void  Crop::input()
{
	for (int j = 0; j < 10; j++)
		waitKey(1);
	imshow("Initial image", m_image);
	cout << "To continue press any key when your cursor are in the area of the opened window with image" << endl;
	waitKey(0);
	cout << "\nInput location of center and size of wanted image." << endl
		<< "These shouldn't exeed size of initial image (size: " << m_image.size() << ")." << endl
		<< "width: ";
	cin >> m_size_crop.width;
	cout << "\nheight:";
	cin >> m_size_crop.height;
	cout << "\nx coodinate:";
	cin >> m_loc.x;
	cout << "\ny coodinate:";
	cin >> m_loc.y;
	cout << "\n";
}
void Crop::check_loc()
{
	if ((m_size_crop.width <= m_image.cols) & (m_size_crop.height <= m_image.rows) & (m_loc.x <= m_image.cols) & (m_loc.y <= m_image.rows))
		crop();
	else
	{
		cout << "Location of centre or size of wanted image is exceeded those of initial image." << endl
			<< "Please, input it again." << endl;
	}
}
void Crop::crop()
{
	getRectSubPix(m_image, m_size_crop, m_loc, m_crop);
	for (int j = 0; j < 10; j++)
		waitKey(1);
	imshow("Cutted image", m_crop);
	cout << "To continue press any key when your cursor are in the area of opened windows with images" << endl;
	waitKey(0);
}