#include "Layer2D.h"
#include <iostream>
#include <vector>
#include <string>

Layer2D::Layer2D(int numberOfMatrices, int matrixHeight, int matrixWidth)
	: numberOfMatrices{ numberOfMatrices }, matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }
{
	if (matrixHeight < 1 || matrixWidth < 1 || numberOfMatrices < 1) throw std::exception("ERROR: incorrect layer dimensions");
}

int Layer2D::getNumberOfMatrices()
{
	return numberOfMatrices;
}

int Layer2D::getMatrixHeight()
{
	return matrixHeight;
}

int Layer2D::getMatrixWidth()
{
	return matrixWidth;
}

std::vector<std::unique_ptr<Matrix>>& Layer2D::getMatrices()
{
	return matrices;
}

//void Layer2D::populateNeurons(Layer& _)
//{
	//matrices = std::vector<std::unique_ptr<Matrix&>>();
	//for (int i = 0; i < numberOfMatrices; i++)
	//	matrices.push_back(std::make_unique<Matrix&>(matrixHeight, matrixWidth));
//}

std::string Layer2D::getSummary()
{
	std::string result = Layer::getSummary() + "\tLayer2D: numberOfMatrices(" + std::to_string(numberOfMatrices)
		+ "), matrixHeight(" + std::to_string(matrixHeight) + "), matrixWidth(" + std::to_string(matrixWidth) + ")\n";
	return result;
}