//
// Created by piotr on 20/04/11.
//


#include "Connection.h"
#include "../Neurons/Neuron.h"


Neuron& Connection::getNeuron()
{
    return connectedNeuron;
}

Connection::Connection(Neuron &connectedNeuron) : connectedNeuron(connectedNeuron) {}
