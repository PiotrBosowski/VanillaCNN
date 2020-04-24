//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H
#define VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H

#include "ContainersConnectingStrategy.h"

class ContainersConnecting1toAll : public ContainersConnectingStrategy
{
public:
    std::vector<std::tuple<Container *, Container *>> proposeConnections(Docker &source, Docker &preceding) override;
};




#endif //VANILLACNN_CLION_CONTAINERSCONNECTING1TOALL_H
