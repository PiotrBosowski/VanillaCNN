//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H


#include "ContainersConnectingStrategy.h"
#include "../NeuronsConnections/NeuronsConnectingStrategy.h"

class ContainersConnecting1toAll : public ContainersConnectingStrategy
{
public:
    ContainersConnecting1toAll();
    void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding) override;
};




#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H
