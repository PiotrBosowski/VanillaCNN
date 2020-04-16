//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSCONNECTING1TOALL_H
#define VANILLACNN_CLION_NEURONSCONNECTING1TOALL_H

#include "NeuronsConnectingStrategy.h"
#include "../Containers/Container.h"

class NeuronsConnecting1toAll : public NeuronsConnectingStrategy
{
public:
    std::vector<Neuron *> proposeSingleNeuronConnections(Container &source, Container *preceding) override;
};



#endif //VANILLACNN_CLION_NEURONSCONNECTING1TOALL_H
