//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"
#include "ExternallyWeightedNeuron.h"
#include "../exceptions/Exceptions.h"
#include "../Connection/ExternallyWeightedConnection.h"


void ExternallyWeightedNeuron::acceptConnection(std::unique_ptr<Connection> connection) {
    throw NeuronsConnectingException("Cannot acceptConnection Externally Weighted Neuron without passing external Weight's reference");
}

void ExternallyWeightedNeuron::calculateValue() {

}

