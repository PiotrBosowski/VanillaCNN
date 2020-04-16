//
// Created by piotr on 20/04/11.
//

#include "InternallyWeightedMatrix.h"
#include "../../Neurons/ExternallyWeightedNeuron.h"
#include "../../exceptions/Exceptions.h"

InternallyWeightedMatrix::InternallyWeightedMatrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth,
                                                   int weightsHeight, int weightsWidth)
                       : Matrix(neuronsFactory, matrixHeight, matrixWidth),
                       weightsHeight(weightsHeight), weightsWidth(weightsWidth)
{
    weights = std::make_unique<Weights>(weightsHeight, weightsWidth);
}

void InternallyWeightedMatrix::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy,
                                       Container &precedingContainer) {
    try{
        for (int i = 0; i < this->neurons.size(); ++i) {
            auto connections = neuronsConnectingStrategy.proposeConnections(*neurons[i], &precedingContainer);
            for (int j = 0; j < connections.size(); j++)
            {
                dynamic_cast<ExternallyWeightedNeuron*>(neurons[i].get())->connect(*connections[j], weights->getWeight(j));
            }
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Internally Weighted Matrices requires Externally Weighted Neurons");
    }
}
