//
// Created by piotr on 20/04/12.
//

#ifndef VANILLACNN_CLION_CONNECTIONSFACTORY_H
#define VANILLACNN_CLION_CONNECTIONSFACTORY_H


#include "Containers/Container.h"

class ConnectionsFactory {

public:
    virtual void makeConnections(int neuronIndex,Container& source, const std::vector<Neuron*>& connections) = 0;
};


#endif //VANILLACNN_CLION_CONNECTIONSFACTORY_H
