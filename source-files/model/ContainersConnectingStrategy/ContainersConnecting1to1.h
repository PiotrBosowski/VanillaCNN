//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H


#include "ContainersConnectingStrategy.h"

class ContainersConnecting1to1 : public ContainersConnectingStrategy
{
public:
    ContainersConnecting1to1();
    void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding) override;
};




#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TO1_H
