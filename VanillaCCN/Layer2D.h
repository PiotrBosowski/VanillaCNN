#pragma once
#include "Layer.h"
#include "Matrix.h"
#include <memory>
class Layer2D : public Layer
{
public:
	Layer2D(int numberOfMatrices, int matrixHeight, int matrixWidth);

protected:
	int numberOfMatrices;
	int matrixHeight;
	int matrixWidth;
	std::vector<std::unique_ptr<Matrix>> matrices;
public:
	int getNumberOfMatrices();
	int getMatrixHeight();
	int getMatrixWidth();
	std::vector<std::unique_ptr<Matrix>>& getMatrices();

	void populateNeurons(std::unique_ptr<Layer>& previousLayer) override;
	void print() override;

public:
	virtual ~Layer2D();
};