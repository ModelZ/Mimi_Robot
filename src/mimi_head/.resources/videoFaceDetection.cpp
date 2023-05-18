#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
	// Open Camera Class 0 is index of camera (If multiple)
	VideoCapture cap = VideoCapture(0);

	//set resolution
	cap.set(CAP_PROP_FRAME_WIDTH, 1280);
	cap.set(CAP_PROP_FRAME_HEIGHT, 720);

	Mat videoImage; //output image from video

	//Read File Image Classification
	CascadeClassifier face_cascade = CascadeClassifier("../../Detect/haarcascade_frontalface_default.xml");

	//Face Classification

	vector<Rect> faceDetect; // Vector of rectangles

	double scaleFactor = 1.3; // Parameter specifying how much the image size is reduced at each image scale.
	int minNeighbors = 10; // Parameter specifying how many neighbors each candidate rectangle should have to retain it.



	while (cap.isOpened())
	{
		cap.read(videoImage); //read image from video frame by frame

		//Convert Image to gray image
		Mat grayImage;
		cvtColor(videoImage, grayImage, COLOR_BGR2GRAY);

		face_cascade.detectMultiScale(grayImage, faceDetect, scaleFactor, minNeighbors); //Face Classification

		imshow("Video", videoImage); //show image

		//Show face position found in rectangle form
		for (Rect found : faceDetect)
			rectangle(videoImage, found, { 0,255,0 }, 5);

		imshow("Video", videoImage); //show image after detection

		if (waitKey(100) == 122) //if pressed key 'z'
			break;

	}

	cap.release(); //close video
	destroyAllWindows(); //close all windows

	return 0;
}