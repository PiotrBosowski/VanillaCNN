#pragma once
#include "Matrix.h"
#include "FeatureDetector.h"

class MatrixConv : public Matrix
{
public:
	MatrixConv(int matrixHeight, int matrixWidth);

private:
	FeatureDetector featureDetector;
};

