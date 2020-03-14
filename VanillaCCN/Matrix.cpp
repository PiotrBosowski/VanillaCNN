#include "Matrix.h"
#include "Exceptions.h"

Matrix::Matrix(NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth)
	: Container{neuronsConnectingStrategy},
	matrixHeight{ matrixHeight },
	matrixWidth{ matrixWidth }
{
	if (matrixHeight < 1 || matrixWidth < 1) throw LayerCreatingException("bad matrix initialization");
	table = std::vector<std::unique_ptr<Neuron>>((long)matrixHeight * (long)matrixWidth);
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
	return *table[(unsigned long)row * (unsigned long)matrixWidth + column];
}

void Matrix::addNeuron(std::unique_ptr<Neuron> newNeuron)
{
	table.push_back(std::move(newNeuron));
}

void Matrix::populateContainer(const Neuron& source, int width, int height)
{
}

void Matrix::connect(Container& preceeding)
{
}
