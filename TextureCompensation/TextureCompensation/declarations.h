#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define COR_PC_ROWS 900
#define COR_PC_COLS 1440
#define COR_PC_Z 2

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
///     从文档中读取三维数组corPC
/// </summary>
/// 
/// <param name = "path"> - 文档完整路径</param>
/// <param name = "corPC"> - corPC三维数组</param>
void readCorPC(string path, double corPC[COR_PC_ROWS][COR_PC_COLS][COR_PC_Z]);


/// <summary>
///     输出读取图像的错误提示信息
/// </summary>
/// <param name = "img"> - 输入图像</param>
/// <param name = "filename"> - 输入图像名</param>
void imOpenIndicator(Mat img, string filename);


/// <summary>
///     在文件名和扩展名之间插入后缀信息, 同时可以更改扩展名
/// </summary>
/// 
/// <param name = "filename"> - 输入文件名 (含扩展名)</param>
/// <param name = "extPrev"> - 输入文件名的扩展名	(含 ".")	</param>
/// <param name = "suffixNew"> - 后缀信息</param>
/// <param name = "exteNew"> - 输出文件名的扩展名 (含 ".")	</param>
/// 
/// <returns>输出文件名</returns>
string addSuffix(string filenameIn, string extPrev, string suffixNew, string extNew);


/// <summary>
///     从文档中读取三维数组corPC
/// </summary>
/// 
/// <param name = "path"> - 相机拍摄的待校正的图像</param>
/// <param name = "corPC"> - corPC三维数组</param>
Mat geomCorr(Mat imCam, double corPC[][COR_PC_COLS][COR_PC_Z]);



void testOpenCV();