#include "Matrix.h"

Matrix::Matrix(int matrixHeight, int matrixWidth) : matrixHeight{matrixHeight}, matrixWidth{matrixWidth}
{
	if (matrixHeight < 1 || matrixWidth < 1) throw std::exception("bad matrix initialization");
	for (int i = 0; i < matrixHeight; i++)
	{
		matrix.push_back(std::vector<std::unique_ptr<Neuron>>{});
		for (int j = 0; j < matrixWidth; j++)
			matrix[i].push_back(std::make_unique<Neuron>());
	}
}

int Matrix::getMatrixHeight()
{
	return matrixHeight;
}

int Matrix::getMatrixWidth()
{
	return matrixWidth;
}

std::vector<std::vector<std::unique_ptr<Neuron>>>& Matrix::getMatrix()
{
	return matrix;
}