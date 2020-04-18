//
// Created by piotr on 20/04/16.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTIONSFACTORY_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTIONSFACTORY_H


#include "ConnectionsFactory.h"

class ExternallyWeightedConnectionsFactory : public ConnectionsFactory{
public:
    void makeConnections(int neuronIndex, Container &source, const std::vector<Neuron *> &connections) override;
};


#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTIONSFACTORY_H
