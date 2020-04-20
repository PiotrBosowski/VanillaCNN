//
// Created by piotr on 20/04/11.
//

#include "Neurons/Neuron.h"
#include "ExternallyWeightedConnection.h"

ExternallyWeightedConnection::ExternallyWeightedConnection(Neuron &connectedNeuron, double &connectionWeight)
        : Connection(connectedNeuron), connectionWeight(connectionWeight) {}
