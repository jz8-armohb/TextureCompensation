#include "declarations.h"


/********************************************************************************
*																				*
*   Description:		进行迭代纹理补偿											*
*																				*
*	Parameters:																	*
*		dir:			图像存储目录												*
*		imPrj:			投影仪原始输入图像 (CV_8UC3格式)							*
*		imCamTrans:		相机拍摄的校正后的图像 (CV_64FC3格式)						*
*		imCompenPrev:	上一轮补偿后的图像 (CV_64FC3格式)							*
*		numCompen:		补偿次数													*
*		lambda:			补偿增益系数 (0.1~0.9)										*
*																				*
*********************************************************************************
*																				*
*   Written and developed by Lipi NIU & Songzhi ZHENG.							*
*   Copyright © 2021 Lipi NIU & Songzhi ZHENG. All rights reserved.				*
*																				*
********************************************************************************/

void iterCompen(string dir, Mat imPrj, Mat imCamTrans, Mat imCompenPrev,
	int numCompen, double lambda) {

	/* 启动计时 */
	double dur;
	clock_t timeStart, timeEnd;
	timeStart = clock();


	/* 暂时未考虑单通道的情况 */
	Mat imCompen = Mat::zeros(PRJ_IN_H, PRJ_IN_W, CV_64FC3);
	Mat imCompen_8UC3 = Mat::zeros(PRJ_IN_H, PRJ_IN_W, CV_8UC3);

	if (numCompen == 1) {
		/* 第1次补偿 */
		for (int i = 0; i < PRJ_IN_H; i++) {
			for (int j = 0; j < PRJ_IN_W; j++) {
				for (int ch = 0; ch < 3; ch++) {
					double prj = (double)imPrj.at<Vec3b>(i, j)[ch];
					double camTr = imCamTrans.at<Vec3d>(i, j)[ch];
					imCompen.at<Vec3d>(i, j)[ch] = (prj + lambda * (prj - camTr));

					/* Debug */
					//cout << "imCompen.at<Vec3b>(" << i << ", " << j << ")[" << ch << "] = " << (int)imCompen.at<Vec3b>(i, j)[ch] << endl;
				}
			}
		}

		imCompen.convertTo(imCompen_8UC3, CV_8UC3);
		imshow("第1次补偿的结果", imCompen_8UC3);

	} else {
		/* 第2次及以后 */
		for (int i = 0; i < PRJ_IN_H; i++) {
			for (int j = 0; j < PRJ_IN_W; j++) {
				for (int ch = 0; ch < 3; ch++) {
					double prev = (double)imCompenPrev.at<Vec3b>(i, j)[ch];
					double prj = (double)imPrj.at<Vec3b>(i, j)[ch];
					double c = imCamTrans.at<Vec3d>(i, j)[ch];
					imCompen.at<Vec3d>(i, j)[ch] = (prev + lambda * (prj - c));
				}
			}
		}

		imCompen.convertTo(imCompen_8UC3, CV_8UC3);
		char windowTitle[20];
		sprintf(windowTitle, "第%d次补偿的结果", numCompen);
		imshow(windowTitle, imCompen_8UC3);
	}


	/* 结束计时 */
	timeEnd = clock();
	dur = double(timeEnd - timeStart) / CLOCKS_PER_SEC;
	cout << "\tTime used: " << dur << " sec.\n";


	//waitKey(0);
}