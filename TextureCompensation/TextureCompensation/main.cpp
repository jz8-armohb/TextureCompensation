#include "declarations.h"

int main(int argc, char** argv) {
	string dirCorPC = argv[1];
	string dirImg = argv[2];

	double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z] = { 0 };
	readCorPC(dirCorPC + "corPC.txt", corPC);

	Mat img = imread(dirImg + "IMG_0001.JPG");
}