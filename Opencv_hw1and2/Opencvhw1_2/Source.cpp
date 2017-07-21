#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstdio>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/opencv.hpp>
const int ENTER = 13;			

using namespace cv;
using namespace std;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

vector<Mat>Imgs;
vector<Mat>ImgGrays;
vector<Mat>ImgBinarys;

int main() {

	
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);
	
	waitKey(0);
	return 0;
}


int HW01_TestFunction() {

	// Fill your answer here

	Mat img = imread("../../testImage/lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	Mat imgGray = imread("../../testImage/lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat imgBinary;
	threshold(imgGray,imgBinary,100.0,255.0,CV_THRESH_BINARY);

	namedWindow("Display lena", CV_WINDOW_AUTOSIZE);
	namedWindow("Display GrayImage", CV_WINDOW_AUTOSIZE);
	namedWindow("Display BinaryImage", CV_WINDOW_AUTOSIZE);

	moveWindow("Display lena", 20, 20);
	moveWindow("Display GrayImage", 420, 20);
	moveWindow("Display BinaryImage", 820, 20);

	imshow("Display lena", img);
	imshow("Display GrayImage", imgGray);
	imshow("Display BinaryImage", imgBinary);
	
	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {


	for(int i=0; i<numberOfImgs; i++)
	{
		//讀圖存進vector
		Imgs.push_back(imread("../../testImage/capture/" + to_string(i + 1) + ".jpg", CV_LOAD_IMAGE_UNCHANGED));
		ImgGrays.push_back(imread("../../testImage/capture/" + to_string(i + 1) + ".jpg", CV_LOAD_IMAGE_GRAYSCALE));
		//二值化
		Mat dst;
		threshold(ImgGrays.at(i), dst, 100.0, 255.0, THRESH_BINARY);
		ImgBinarys.push_back(dst);

		namedWindow("Display", CV_WINDOW_AUTOSIZE);
		namedWindow("Display Gray", CV_WINDOW_AUTOSIZE);
		namedWindow("Display Binary", CV_WINDOW_AUTOSIZE);

		moveWindow("Display", 20, 20);
		moveWindow("Display Gray", 420, 20);
		moveWindow("Display Binary", 820, 20);

		imshow("Display", Imgs.at(i));
		imshow("Display Gray", ImgGrays.at(i));
		imshow("Display Binary", ImgBinarys.at(i));
		

		while (true) {									//輸入enter跳至下一張圖
			if (cvWaitKey(0) == ENTER) {
				break;
			}
		}
		destroyAllWindows();
		// Fill your answer here
	}
	return 0;
}

