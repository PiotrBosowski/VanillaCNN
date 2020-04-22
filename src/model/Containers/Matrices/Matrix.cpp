//
// Created by piotr on 20/04/11.
//


#include "Matrix.h"
#include "Exceptions/Exceptions.h"

Matrix::Matrix(int matrixHeight, int matrixWidth)
            : Container(matrixHeight*matrixWidth),
            matrixHeight{ matrixHeight },
             matrixWidth{ matrixWidth }
{
    if (matrixHeight < 0 || matrixWidth < 0) throw ContainersCreatingException("bad matrix initialization");
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

unsigned int Matrix::getHeightFromIndex(unsigned int neuronIndex) {
    return neuronIndex/matrixHeight;
}

unsigned int Matrix::getWidthFromIndex(unsigned int neuronIndex) {
    return neuronIndex%matrixWidth;
}

