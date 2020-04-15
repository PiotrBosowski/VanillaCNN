//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINER_H
#define VANILLACNN_CLION_CONTAINER_H

#include <memory>
#include "../NeuronsConnections/NeuronsConnectingStrategy.h"
#include "../NeuronsFactories/NeuronsFactory.h"

class Neuron;

class Container
{
protected:
    std::vector<std::unique_ptr<Neuron>> neurons;

public:
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Container& preceedingContainer) = 0;
    virtual Neuron& getNeuron(unsigned int index);
    unsigned int getNumberOfNeurons();
};



#endif //VANILLACNN_CLION_CONTAINER_H
