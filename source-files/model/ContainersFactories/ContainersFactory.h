//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSFACTORY_H
#define VANILLACNN_CLION_CONTAINERSFACTORY_H

#include <memory>
#include "../Containers/Container.h"
#include "../ContainersConnectingStrategy/ContainersConnectingStrategy.h"

class ContainersFactory
{
public:
    virtual std::unique_ptr<Container> createContainer(
            ContainersConnectingStrategy& containersConnectingStrategy,
            NeuronsFactory& neuronsFactory,
            NeuronsConnectingStrategy& neuronsConnectingStrategy) = 0;
};



#endif //VANILLACNN_CLION_CONTAINERSFACTORY_H
