#include "declarations.h"

int main(int argc, char** argv) {
	string dirCorPC = argv[1];
	string dirIm = argv[2];

	/* 从文档中读取corPC */
	double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z] = { 0 };
	readCorPC(dirCorPC + "corPC.txt", corPC);
	//readCorPC(dirCorPC + "matrix3.txt", corPC);

	/* 几何校正*/
	Mat imCam = imread(dirIm + "IMG_0001.JPG");
	//Mat imPrj = imread(dirIm + "im_board.jpg");
	Mat imCamTrans = geomCorr(imCam, corPC, dirIm);

	waitKey(0);
	return 0;
}