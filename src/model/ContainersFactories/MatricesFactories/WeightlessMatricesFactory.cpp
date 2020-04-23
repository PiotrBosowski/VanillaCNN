//
// Created by piotr on 20/04/11.
//


#include <Exceptions/Exceptions.h>
#include "WeightlessMatricesFactory.h"
#include "Containers/Matrices/WeightlessMatrix.h"

WeightlessMatricesFactory::WeightlessMatricesFactory(int matrixHeight, int matrixWidth)
        : matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }
{
    if(matrixHeight < 1 || matrixWidth < 1) throw ContainersCreatingException("Cant create weightless container with negative dimensions");
}

std::unique_ptr<Container> WeightlessMatricesFactory::createContainer() {
    return std::make_unique<WeightlessMatrix>(matrixHeight, matrixWidth);
}
