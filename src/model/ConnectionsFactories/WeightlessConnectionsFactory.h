//
// Created by piotr on 20/04/12.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSCONNECTIONSFACTORY_H
#define VANILLACNN_CLION_WEIGHTLESSCONNECTIONSFACTORY_H


#include "ConnectionsFactory.h"

class WeightlessConnectionsFactory : public ConnectionsFactory {
public:
    void makeConnections(Container &source, const std::vector<Neuron *> &connections) override;
};


#endif //VANILLACNN_CLION_WEIGHTLESSCONNECTIONSFACTORY_H
