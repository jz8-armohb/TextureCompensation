#include "declarations.h"

int main(int argc, char** argv) {
	string dirCorPC = argv[1];
	string dirIm = argv[2];

	/* 从文档中读取corPC */
	cout << "\nReading corPC from file...\n";
	double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z] = { 0 };
	readCorPC(dirCorPC + "corPC.txt", corPC);

	/* 几何校正*/
	cout << "\nCorrecting image...\n";
	Mat imCam = imread(dirIm + "IMG_0002.JPG");
	imOpenIndicator(imCam, "IMG_0002.JPG");
	//Mat imPrj = imread(dirIm + "im_board.jpg");
	//imOpenIndicator(imPrj, "im_board.jpg");
	Mat imCamTrans = geomCorr(imCam, corPC);


	//testOpenCV();
	waitKey(0);
	return 0;
}