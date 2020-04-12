//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRICESFACTORY_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRICESFACTORY_H


#include "MatricesFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnectingStrategy.h"

class InternallyWeightedMatricesFactory : public MatricesFactory
{
public:
    InternallyWeightedMatricesFactory(int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth);
    std::unique_ptr<Container> createContainer(ContainersConnectingStrategy& containersConnectingStrategy,
                                               NeuronsFactory& neuronsFactory,
                                               NeuronsConnectingStrategy& neuronsConnectingStrategy) override;

private:
    int matrixHeight;
    int matrixWidth;
    int weightsHeight;
    int weightsWidth;
};


#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRICESFACTORY_H
