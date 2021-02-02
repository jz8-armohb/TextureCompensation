#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define COR_PC_ROWS 900
#define COR_PC_COLS 1440
#define COR_PC_Z 2
#define PRJ_IN_W 1920	// ͶӰ������ͼ��Ŀ�
#define PRJ_IN_H 1200


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <Eigen/SVD>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;
using namespace Eigen;



/* Function declarations */

/// <summary>
///     ���ĵ��ж�ȡ��ά����corPC
/// </summary>
/// 
/// <param name = "path"> - �ĵ�����·��</param>
/// <param name = "corPC"> - corPC��ά����</param>
void readCorPC(string path, double corPC[][COR_PC_COLS][COR_PC_Z]);


/// <summary>
///     �����ȡͼ��Ĵ�����ʾ��Ϣ
/// </summary>
/// <param name = "img"> - ����ͼ��</param>
/// <param name = "filename"> - ����ͼ����</param>
void imOpenIndicator(Mat img, string filename);


/// <summary>
///     ���ļ�������չ��֮������׺��Ϣ, ͬʱ���Ը�����չ��
/// </summary>
/// 
/// <param name = "filename"> - �����ļ��� (����չ��)</param>
/// <param name = "extPrev"> - �����ļ�������չ��	(�� ".")	</param>
/// <param name = "suffixNew"> - ��׺��Ϣ</param>
/// <param name = "exteNew"> - ����ļ�������չ�� (�� ".")	</param>
/// 
/// <returns>����ļ���</returns>
string addSuffix(string filenameIn, string extPrev, string suffixNew, string extNew);


/// <summary>
///     ���ĵ��ж�ȡ��ά����corPC
/// </summary>
/// 
/// <param name = "path"> - �������Ĵ�У����ͼ�� (CV_8UC3��ʽ)</param>
/// <param name = "corPC"> - corPC��ά����</param>
/// 
/// <returns>��������У����ͼ�� (CV_64FC3��ʽ)</returns>
Mat geomCorr(Mat imCam, double corPC[][COR_PC_COLS][COR_PC_Z]);


/// <summary>
///     ���е���������
/// </summary>
/// 
/// <param name = "dir"> - ͼ��洢Ŀ¼</param>
/// <param name = "imPrj"> - ͶӰ��ԭʼ����ͼ�� (CV_8UC3��ʽ)</param>
/// <param name = "imCamTrans"> - ��������У�����ͼ�� (CV_64FC3��ʽ)</param>
/// <param name = "imCompenPrev"> - ��һ�ֲ������ͼ�� (CV_64FC3��ʽ)</param>
/// <param name = "numCompen"> - ��������</param>
/// <param name = "lambda"> - ��������ϵ�� (0.1~0.9)</param>
void iterCompen(string dir, Mat imPrj, Mat imCamTrans, Mat imCompenPrev, int numCompen, double lambda);


void testOpenCV();