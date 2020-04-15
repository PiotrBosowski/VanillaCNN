//
// Created by piotr on 20/04/11.
//


#include "Matrix.h"
#include "../../exceptions/Exceptions.h"

Matrix::Matrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth)
            :
            matrixHeight{ matrixHeight },
             matrixWidth{ matrixWidth }
{
    if (matrixHeight < 1 || matrixWidth < 1) throw LayerCreatingException("bad matrix initialization");
    for (int i = 0; i < matrixWidth * matrixHeight; i++)
    {
        neurons.push_back(neuronsFactory.createNeuron());
    }
}

int Matrix::getMatrixHeight() const
{
    return matrixHeight;
}

int Matrix::getMatrixWidth() const
{
    return matrixWidth;
}

Neuron& Matrix::getNeuron(unsigned int row, unsigned int column)
{
    if(row * column < neurons.size())
        return *neurons[(unsigned long)row * (unsigned long)matrixWidth + column];
    else throw ContainerOutOfRangeException();
}
