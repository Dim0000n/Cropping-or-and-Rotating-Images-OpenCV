#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <sstream>


using namespace std;
using namespace cv;


void hello() {
	system("cls");
	cout
		<< "\n----------------------------------------------------" << endl
		<< "\nHello! This program can to crop and(or) rotate images. \n" << endl
		<< "\n----------------------------------------------------" << endl
		<< "To select CROP mode INPUT C\n" << endl
		<< "To select ROTATION mode INPUT R\n" << endl
		<< "To EXIT INPUT E" << endl
		
		<< "\n----------------------------------------------------" << endl
		<< "Regards," << endl
		<< "Dmity Utev." << endl
		<< "\n\n>> ";
}
Mat whichcrop(const Mat& crop_image, const Mat& input_crop1, const Mat& input_crop)
{
	cout << "\n Wich image do you want to continue cropping?" << endl
		<< "1.Initial image." << endl
		<< "2.Image from this iteration." << endl
		<< "3.Image from the previous iteration." << endl
		<< "\nInput number of position" << endl;
	int num_pos;
	cin >> num_pos;
	switch (num_pos)
	{
	case 1:
		return input_crop1;
	case 2:
		return crop_image;
	case 3:
		return input_crop;
	}

}
void save(const Mat& save_image)
{
	cout << "\nDo you want to save the result? (Y/N):";
	char save;
	cin >> save;
	cout << "\n";
	if (save == 89 || save == 121)
	{
		cout << "\nInput the name of image wich will be saved. The image will be saved in .png format:";
		string save_name;
		cin >> save_name;
		stringstream full_name;
		full_name << save_name << ".png" << endl;
		
		
		full_name>> save_name;
		imwrite(save_name, save_image);
	}
}
bool contin()
{
	cout << "\nDo you want to continue the process (Y/N): " << endl;
	char cont;
	cin >> cont;
	cout << "\n";
	if (cont == 89 || cont == 121)
		return 0;
	else
		return 1;
}