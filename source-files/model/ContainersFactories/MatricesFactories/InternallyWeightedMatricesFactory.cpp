//
// Created by piotr on 20/04/11.
//


#include "InternallyWeightedMatricesFactory.h"
#include "../../Containers/Matrices/InternallyWeightedMatrix.h"

InternallyWeightedMatricesFactory::InternallyWeightedMatricesFactory(int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth)
        : matrixHeight{ matrixHeight }, matrixWidth{ matrixWidth }, weightsHeight{ weightsHeight }, weightsWidth{ weightsWidth }
{
}

std::unique_ptr<Container>
InternallyWeightedMatricesFactory::createContainer(ContainersConnectingStrategy &containersConnectingStrategy,
                                                   NeuronsFactory &neuronsFactory,
                                                   NeuronsConnectingStrategy &neuronsConnectingStrategy) {
    return std::unique_ptr<Container>();
}