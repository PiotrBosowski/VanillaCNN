//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H


#include "ContainersConnectingStrategy.h"

class ContainersConnecting1toRandom : public ContainersConnectingStrategy
{
public:
    ContainersConnecting1toRandom();
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer & previousLayer);
};



#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H
