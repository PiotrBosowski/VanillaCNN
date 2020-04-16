//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"
#include "ExternallyWeightedNeuron.h"
#include "../exceptions/Exceptions.h"


void ExternallyWeightedNeuron::connect(Neuron &preceding) {
    throw NeuronsConnectingException("Cannot connect Externally Weighted Neuron without passing external Weight's reference");
}

void ExternallyWeightedNeuron::connect(Neuron &preceding, double &) {

}

void ExternallyWeightedNeuron::calculateValue() {

}

