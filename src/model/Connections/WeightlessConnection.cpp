//
// Created by piotr on 20/04/16.
//

#include "WeightlessConnection.h"

Weight &WeightlessConnection::getWeight() {
    static Weight weight{1.0};
    return weight;
}

WeightlessConnection::WeightlessConnection(Neuron &connectedNeuron) : Connection(connectedNeuron) {}
