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


Mat geomCorr(Mat imCam, double corPC[][COR_PC_COLS][COR_PC_Z], string saveDir);