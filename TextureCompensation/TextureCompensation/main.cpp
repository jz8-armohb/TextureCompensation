﻿#include "declarations.h"

int main(int argc, char** argv) {
	string dirCorPC = argv[1];
	string dirImg = argv[2];

	double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z] = { 0 };
	readCorPC(dirCorPC + "corPC.txt", corPC);

<<<<<<< Updated upstream
	Mat img = imread(dirImg + "IMG_0001.JPG");
=======
	/* 几何校正*/
	cout << "\nCorrecting image...\n";
	Mat imCam = imread(dirIm + "child_cam.JPG");
	imOpenIndicator(imCam, "child_cam.JPG");
	Mat imPrj = imread(dirIm + "child_prj.jpg");
	imOpenIndicator(imPrj, "child_prj.jpg");
	Mat imCamTrans = geomCorr(imCam, corPC);

	/* 迭代补偿 */
	cout << "\nExecuting iteration compensation...\n";
	iterCompen(dirIm, imPrj, imCamTrans, imPrj, 1, 0.6);



	//testOpenCV();
	waitKey(0);
	return 0;
>>>>>>> Stashed changes
}