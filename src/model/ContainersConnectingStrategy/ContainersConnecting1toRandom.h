//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H


#include "ContainersConnectingStrategy.h"

class ContainersConnecting1toRandom : public ContainersConnectingStrategy
{
public:
    std::vector<std::tuple<Container *, Container *>> proposeConnections(Docker &source, Docker *preceding) override;
};



#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TORANDOM_H
