//
// Created by piotr on 20/04/11.
//


#include <Exceptions/Exceptions.h>
#include "InternallyWeightedMatricesFactory.h"
#include "Containers/Matrices/InternallyWeightedMatrix.h"

InternallyWeightedMatricesFactory::InternallyWeightedMatricesFactory(int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth)
        : matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }, weightsHeight{ weightsHeight }, weightsWidth{ weightsWidth }
{
    if(matrixHeight < 1 || matrixWidth < 1) throw ContainersCreatingException("Cant create container with negative dimensions");
    if(weightsHeight < 1 || weightsWidth < 1) throw ContainersCreatingException("Cant create interanlly weighted container with weights negative dimensions");
}

std::unique_ptr<Container> InternallyWeightedMatricesFactory::createContainer() {
    return std::make_unique<InternallyWeightedMatrix>(matrixHeight, matrixWidth, weightsHeight, weightsWidth);
}