//
// Created by piotr on 20/04/11.
//


#include "WeightlessMatricesFactory.h"
#include "../../Containers/Matrices/WeightlessMatrix.h"

WeightlessMatricesFactory::WeightlessMatricesFactory(int matrixHeight, int matrixWidth)
        : matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }
{
}

std::unique_ptr<Container>
WeightlessMatricesFactory::createContainer(NeuronsFactory& neuronsFactory) {
    return std::make_unique<WeightlessMatrix>(neuronsFactory, matrixHeight, matrixWidth);
}
