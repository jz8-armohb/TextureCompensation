#include "declarations.h"

void testOpenCV() {
	Mat img = imread("C:\\Users\\s.z.zheng\\Pictures\\test_img\\pexels-pixabay-164634 (Small).jpg");
	imOpenIndicator(img, "pexels-pixabay-164634 (Small).jpg");
	Mat imgCopy = Mat::zeros(480, 640, CV_64FC3);
	//imshow("Original", img);

	for (int i = 0; i < 480; i++) {
		for (int j = 0; j < 640; j++) {
			for (int ch = 0; ch < 3; ch++) {
				imgCopy.at<Vec3d>(i, j)[ch] = img.at<Vec3b>(i, j)[ch];
			}
		}
	}
	cout << (int)imgCopy.at<Vec3d>(200, 200)[0] << "\t" << (int)imgCopy.at<Vec3d>(200, 200)[1] << "\t" << (int)imgCopy.at<Vec3d>(200, 200)[2] << endl;
	//imshow("Copy", imgCopy);
}