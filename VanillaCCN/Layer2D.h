#pragma once
#include "Layer.h"
#include "Matrix.h"
#include <memory>

class Layer2D : public Layer
{
public:
	Layer2D(int numberOfMatrices, int matrixHeight, int matrixWidth);

protected:
	int matrixHeight;
	int matrixWidth;

public:
	std::string getSummary() override;
	int getMatrixHeight();
	int getMatrixWidth();
};