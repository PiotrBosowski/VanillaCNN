//
// Created by piotr on 20/04/11.
//

#include "WeightlessMatrix.h"
#include "../../Neurons/WeightlessNeuron.h"
#include "../../exceptions/Exceptions.h"

WeightlessMatrix::WeightlessMatrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth)
    : Matrix(neuronsFactory, matrixHeight, matrixWidth) {}

void WeightlessMatrix::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, Container &precedingContainer) {
    try{
        for (auto & neuron : neurons) {
            auto connections = neuronsConnectingStrategy.proposeConnections(*neuron, &precedingContainer);
            for (auto & conn : connections)
            {
                dynamic_cast<WeightlessNeuron*>(neuron.get())->connect(*conn);
            }
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Weightless Matrix can only be used with Weightless Neurons");
    }
}

