#include "declarations.h"


/********************************************************************************
*																				*
*   Description:		从文档中读取三维数组corPC									*
*																				*
*	Parameters:																	*
*		path:			文档完整路径												*
*		corPC:			corPC三维数组												*
*																				*
*********************************************************************************
*																				*
*   Written and developed by Songzhi ZHENG.										*
*   Copyright © 2021 Songzhi ZHENG. All rights reserved.				*
*																				*
********************************************************************************/

void readCorPC(string path, double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z]) {
	/* 启动计时 */
	double dur;
	clock_t timeStart, timeEnd;
	timeStart = clock();


	memset(corPC, 0, COR_PC_ROWS * COR_PC_COLS * COR_PC_Z);
	ifstream fileCorPC(path, ios::in);
	string lineCorPC;


	cout << "\nReading corPC from file...\n";
	if (fileCorPC.is_open()) {
		cout << "\t'" << path << "' opened.\n";
		int i = 0;

		while (getline(fileCorPC, lineCorPC)) {
			stringstream ss(lineCorPC);
			string sub;
			vector<string> subArray;

			while (getline(ss, sub, '\t')) {
				subArray.push_back(sub);
			}

			for (size_t m = 0; m < subArray.size() / 2; m++) {
				corPC[i][m][0] = stod(subArray[m]);
				corPC[i][m][1] = stod(subArray[m + COR_PC_COLS]);
			}
			i++;
		}
	} else {
		cerr << "\tFailed to open '" << path << "'.\n";
	}
	

	/* 结束计时 */
	timeEnd = clock();
	dur = double(timeEnd - timeStart) / CLOCKS_PER_SEC;
	cout << "\tTime used: " << dur << " sec.\n";


	/* Test */
	//cout << corPC[3][1][0] << "\t" << corPC[3][1][1] << "\n";
	//for (int i = 0; i < COR_PC_ROWS; i++) {
	//	for (int j = 0; j < COR_PC_COLS; j++) {
	//		cout << corPC[i][j][0] << "\t" << corPC[i][j][1] << "\t";
	//	}
	//	cout << endl;
	//}
}