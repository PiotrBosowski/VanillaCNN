//
// Created by piotr on 20/04/11.
//

#include <Weights/Weight.h>
#include "Neurons/Neuron.h"
#include "ExternallyWeightedConnection.h"

ExternallyWeightedConnection::ExternallyWeightedConnection(Neuron &connectedNeuron, Weight &connectionWeight)
        : Connection(connectedNeuron), connectionWeight(connectionWeight) {}

Weight &ExternallyWeightedConnection::getWeight() {
    return connectionWeight;
}
