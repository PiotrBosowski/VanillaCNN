//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H
#define VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H

#include "../NeuronsConnections/NeuronsConnectingStrategy.h"

class Docker;

class ContainersConnectingStrategy
{
public:
    virtual std::vector<std::tuple<Container*, Container*>> proposeConnections(Docker& source, Docker* preceding) = 0;
};

#endif //VANILLACNN_CLION_CONTAINERSCONNECTINGSTRATEGY_H
