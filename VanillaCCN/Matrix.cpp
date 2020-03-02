#include "Matrix.h"
#include "NeuronRegular.h"

Matrix::Matrix(int matrixHeight, int matrixWidth)
	: matrixHeight{matrixHeight}, matrixWidth{matrixWidth}
{
	if (matrixHeight < 1 || matrixWidth < 1) throw std::exception("bad matrix initialization");
	table = std::vector<std::unique_ptr<Neuron>>(matrixHeight * matrixWidth);
}

int Matrix::getMatrixHeight()
{
	return matrixHeight;
}

int Matrix::getMatrixWidth()
{
	return matrixWidth;
}

Neuron& Matrix::getNeuron(unsigned int row, unsigned int column)
{
	return *(table[row * matrixWidth + column]);
}
