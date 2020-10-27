#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "Crop.h"
#include "Rotate.h"


using namespace std;
using namespace cv;

void hello();
Mat whichcrop(const Mat& crop_image, const Mat& input_crop1, const Mat& input_crop);
void save(const Mat& save_image);
bool contin();


int main()
{

	for (;;) {
		system("color 2");
		hello();
		char mode;
		bool i = 0;
		cin >> mode;
		if (mode == 67 || mode == 99)
		{
			for (;;)
			{
				system("cls");
				cout << "You chose the cropping mode" << endl
					<< "To EXIT mode INPUT E" << endl
					<< "\n___________________________" << endl
					<< "Input the name of image (example.xxx) or E: ";
				string input_crop_name;
				cin >> input_crop_name;
				cout << "\n";
				if (input_crop_name == "E" || input_crop_name == "e")
					break;
				Mat input_crop = imread(input_crop_name);
				Mat input_crop1 = input_crop;
				if (!input_crop.empty())
				{
					bool i = 0;
					while (i == 0)
					{
						Crop to_crop(input_crop);
						to_crop.input();
						to_crop.check_loc();
						Mat crop_image = to_crop.getCropImage();
						if (!crop_image.empty())
						{
							save(crop_image);
							i = contin();
							if (i == 0)
							{
								Mat which;
								which = whichcrop(crop_image, input_crop1, input_crop);
								input_crop = which;
							}
						}
						system("cls");
						destroyAllWindows();
					}
				}
				else
				{
					cout << "The image not found. Please, try again." << endl;
					waitKey(2000);
				}

			}

		}
		if (mode == 82 || mode == 114)
		{
			for (;;)
			{
				system("cls");
				cout << "You chose the rotation mode" << endl;
				cout << "To EXIT mode PRESS E" << endl;
				cout << "\n___________________________" << endl;
				cout << "Input the name of image (example.xxx) or E: ";
				string input_rot_name;
				cin >> input_rot_name;
				cout << "\n";
				if (input_rot_name == "E" || input_rot_name == "e")
					break;
				Mat input_rot = imread(input_rot_name, IMREAD_GRAYSCALE);
				if (!input_rot.empty())
				{
					bool i = 0;
					while (i == 0)
					{
						Rotate to_rotate(input_rot);
						to_rotate.rot();
						Mat rot_image = to_rotate.getRotated();
						save(rot_image);
						i = contin();
						system("cls");
						destroyAllWindows();
					}
				}
				else
				{
					cout << "The image not found. Please, try again." << endl;
					waitKey(2000);
				}
			}
		}
		if (mode == 69 || mode == 101)
			return 0;
	}
}

