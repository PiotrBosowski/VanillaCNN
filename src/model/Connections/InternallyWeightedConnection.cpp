//
// Created by piotr on 20/04/11.
//

#include "InternallyWeightedConnection.h"

InternallyWeightedConnection::InternallyWeightedConnection(Neuron &connNeuron) : Connection(connNeuron)
{}

Weight &InternallyWeightedConnection::getWeight() {
    return connectionWeight;
}

