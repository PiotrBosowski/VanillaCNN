//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINER_H
#define VANILLACNN_CLION_CONTAINER_H

#include <memory>
#include <ostream>
#include "../Neurons/NeuronsConnections/NeuronsConnectingStrategy.h"
#include "../Connections/ConnectionsFactories/ConnectionsFactory.h"


class Neuron;
class ConnectionsFactory;

class Container
{
protected:
    std::vector<std::unique_ptr<Neuron>> neurons;

public:
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, ConnectionsFactory& connectionsFactory, Container& precedingContainer) = 0;
    Neuron& getNeuron(unsigned int index);
    unsigned int getNumberOfNeurons();

    friend std::ostream &operator<<(std::ostream &os, const Container &container);
};

#endif //VANILLACNN_CLION_CONTAINER_H
