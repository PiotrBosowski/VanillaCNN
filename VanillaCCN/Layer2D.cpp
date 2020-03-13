#include "Layer2D.h"
#include <iostream>
#include <vector>
#include <string>
#include "Exceptions.h"

Layer2D::Layer2D(int numberOfMatrices, int matrixHeight, int matrixWidth)
	: Layer{ numberOfMatrices }, matrixHeight { matrixHeight}, matrixWidth{ matrixWidth }
{
	if (matrixHeight < 1 || matrixWidth < 1 || numberOfMatrices < 1) throw LayerCreatingException("ERROR: incorrect layer dimensions");
}

std::string Layer2D::getSummary()
{
	std::string result = Layer::getSummary() + "\tLayer2D: numberOfMatrices(" + std::to_string(numberOfContainers)
		+ "), matrixHeight(" + std::to_string(matrixHeight) + "), matrixWidth(" + std::to_string(matrixWidth) + ")\n";
	return result;
}

int Layer2D::getMatrixHeight()
{
	return matrixHeight;
}

int Layer2D::getMatrixWidth()
{
	return matrixWidth;
}
