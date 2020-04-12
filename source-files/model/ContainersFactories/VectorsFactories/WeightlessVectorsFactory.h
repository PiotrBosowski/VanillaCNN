//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSVECTORSFACTORY_H
#define VANILLACNN_CLION_WEIGHTLESSVECTORSFACTORY_H


#include "VectorsFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnectingStrategy.h"

class WeightlessVectorsFactory : public VectorsFactory
{
public:
    explicit WeightlessVectorsFactory(int numberOfNeurons);

    std::unique_ptr<Container> createContainer(
            ContainersConnectingStrategy& containersConnectingStrategy,
            NeuronsFactory& neuronsFactory,
            NeuronsConnectingStrategy& neuronsConnectingStrategy) override;
private:
    int numberOfNeurons;
};




#endif //VANILLACNN_CLION_WEIGHTLESSVECTORSFACTORY_H
