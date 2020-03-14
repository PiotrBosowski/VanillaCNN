#include "Matrix.h"
#include "Exceptions.h"

Matrix::Matrix(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth)
	: Container{neuronFactory, neuronsConnectingStrategy},
	matrixHeight{ matrixHeight },
	matrixWidth{ matrixWidth }
{
	if (matrixHeight < 1 || matrixWidth < 1) throw LayerCreatingException("bad matrix initialization");
	for (int i = 0; i < matrixWidth * matrixHeight; i++)
	{
		table.push_back(neuronFactory.createNeuron());
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

Neuron& Matrix::getNeuron(unsigned int index)
{
	if (index < table.size())
		return *table[index];
	else throw ContainerOutOfRangeException();
}

Neuron& Matrix::getNeuron(unsigned int row, unsigned int column)
{
	if(row * column < table.size())
		return *table[(unsigned long)row * (unsigned long)matrixWidth + column];
	else throw ContainerOutOfRangeException();
}

unsigned int Matrix::getNumberOfNeurons()
{
	return matrixWidth * matrixHeight;
}
