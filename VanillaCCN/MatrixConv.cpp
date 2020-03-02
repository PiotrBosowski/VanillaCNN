#include "MatrixConv.h"

MatrixConv::MatrixConv(int matrixHeight, int matrixWidth)
	: Matrix{ matrixHeight, matrixWidth }, featureDetector{matrixHeight, matrixWidth}
{
}
