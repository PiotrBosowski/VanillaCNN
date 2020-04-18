//
// Created by piotr on 20/04/11.
//


#include "WeightlessMatricesFactory.h"
#include "../../Matrices/WeightlessMatrix.h"

WeightlessMatricesFactory::WeightlessMatricesFactory(int matrixHeight, int matrixWidth)
        : matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }
{
}

std::unique_ptr<Container>
WeightlessMatricesFactory::createContainer() {
    return std::make_unique<WeightlessMatrix>(matrixHeight, matrixWidth);
}
