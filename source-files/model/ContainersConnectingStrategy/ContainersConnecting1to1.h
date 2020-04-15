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
    ContainersConnecting1to1();
    void proposeConnections(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding) override;
    std::vector<std::tuple<Container*, Container*>> proposeConnections(Docker& source, Docker* preceding);

};




#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H
