//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINER_H
#define VANILLACNN_CLION_CONTAINER_H

#include <memory>
#include <ostream>
#include "NeuronsConnections/NeuronsConnectingStrategy.h"
#include "ConnectionsFactories/ConnectionsFactory.h"

class Neuron;
class ConnectionsFactory;

class Container
{
protected:
    std::vector<std::unique_ptr<Neuron>> neurons;
public:
    Container(int numberOfNeurons);

public:
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, ConnectionsFactory& connectionsFactory, Container& precedingContainer) = 0;
    Neuron& getNeuron(unsigned int index);
    unsigned int getNumberOfNeurons();
};

#endif //VANILLACNN_CLION_CONTAINER_H
