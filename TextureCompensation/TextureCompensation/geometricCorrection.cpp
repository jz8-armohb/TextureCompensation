#include "declarations.h"


/********************************************************************************
*																				*
*   Description:		从文档中读取三维数组corPC									*
*																				*
*	Parameters:																	*
*		imCam:			相机拍摄的待校正的图像										*
*		corPC:			corPC三维数组												*
*																				*
*********************************************************************************
*																				*
*   Written and developed by Lipi NIU & Songzhi ZHENG.							*
*   Copyright © 2021 Lipi NIU & Songzhi ZHENG. All rights reserved.				*
*																				*
********************************************************************************/

Mat geomCorr(Mat imCam, double corPC[][COR_PC_COLS][COR_PC_Z]) {
	/* 启动计时 */
	double dur;
	clock_t timeStart, timeEnd;
	timeStart = clock();


	Mat imCamTrans;		// 经过几何校正的相机拍摄的投影图像
	int numChannel = imCam.channels();


	switch (numChannel) {
	case 1: {
		/* 黑白图像 */
		imCamTrans = Mat::zeros(1200, 1920, CV_64FC1);
		for (int i = 300; i < 900; i++) {
			for (int j = 480; j < 1440; j++) {
				int ii = floor(corPC[i][j][0]);
				int jj = floor(corPC[i][j][1]);
				double u = corPC[i][j][0] - ii;
				double v = corPC[i][j][1] - jj;

				imCamTrans.at<uchar>(i, j) = uchar(
					(1 - u) * (1 - v) * imCam.at<uchar>(ii, jj)
					+ (1 - u) * v * imCam.at<uchar>(ii, jj + 1)
					+ u * (1 - v) * imCam.at<uchar>(ii + 1, jj)
					+ u * v * imCam.at<uchar>(ii + 1, jj + 1));
			}
		}

		break;
	}

	case 3: {
		/* RGB图像 */
		imCamTrans = Mat::zeros(1200, 1920, CV_64FC3);
		for (int i = 300; i < 900; i++) {
			for (int j = 480; j < 1440; j++) {
				int ii = floor(corPC[i][j][0]);
				int jj = floor(corPC[i][j][1]);
				double u = corPC[i][j][0] - ii;
				double v = corPC[i][j][1] - jj;

				/* Debug */
				//printf("-----------------------------------------------------------------------------------\n");
				//printf("i = %d, j = %d\n", i, j);
				//printf("corPC[%d][%d][0] = %lf,\tcorPC[%d][%d][1] = %lf\n", 
				//	i, j, corPC[i][j][0], 
				//	i, j, corPC[i][j][1]);
				//printf("ii= %d,\tjj = %d,\tu = %lf,\tv = %lf\n", ii, jj, u, v);

				for (int ch = 0; ch < numChannel; ch++) {

					/* Debug */
					//if (i == 300 && j == 582) {
					//	cout << "Check point:\n";
					//}

					int i1 = imCam.at<Vec3b>(ii, jj)[ch];
					int i2 = imCam.at<Vec3b>(ii, jj + 1)[ch];
					int i3 = imCam.at<Vec3b>(ii + 1, jj)[ch];
					int i4 = imCam.at<Vec3b>(ii + 1, jj + 1)[ch];

					/* 溢出处理 */
					double temp = 
						(1 - u) * (1 - v) * i1
						+ (1 - u) * v * i2
						+ u * (1 - v) * i3
						+ u * v * i4;
					if (temp > 255) {
						temp = 255;
					} else if (temp < 0) {
						temp = 0;
					}
					imCamTrans.at<Vec3d>(i, j)[ch] = temp;


					///* Debug */
					//printf("i1= %d,\ti2 = %d,\ti3 = %d,\ti4 = %d\n", (int)i1, (int)i2, (int)i3, (int)i4);
					//printf("imCamTrans.at<Vec3b>(%d, %d)[%d] = %lf\n", i, j, ch, imCamTrans.at<Vec3d>(i, j)[ch]);
				}
			}
		}

		break;
	}

	default:
		break;
	}


	/* 结束计时 */
	timeEnd = clock();
	dur = double(timeEnd - timeStart) / CLOCKS_PER_SEC;
	cout << "\tTime used: " << dur << " sec.\n";


	imshow("Geometric corrected image", imCamTrans);
	return imCamTrans;
}