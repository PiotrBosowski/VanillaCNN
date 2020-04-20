//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H

#include <vector>
#include <tuple>
#include "ContainersConnectingStrategy.h"

class ContainersConnecting1to1 : public ContainersConnectingStrategy
{
public:
    std::vector<std::tuple<Container*, Container*>> proposeConnections(Docker& source, Docker* preceding) override;
};

#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H
