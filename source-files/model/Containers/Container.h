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
public:
    Container();

public:
    virtual void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Container& preceedingContainer);
    virtual Neuron& getNeuron(unsigned int index) = 0;
    virtual unsigned int getNumberOfNeurons() = 0;
};



#endif //VANILLACNN_CLION_CONTAINER_H
