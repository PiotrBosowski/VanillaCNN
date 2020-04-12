//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H
#define VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H

#include "../NeuronsConnections/NeuronsConnectingStrategy.h"

class Docker;
class Layer;

class ContainersConnectingStrategy
{
public:
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding) = 0;
};



#endif //VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H
