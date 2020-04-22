//
// Created by piotr on 20/04/11.
//

#include "InternallyWeightedMatrix.h"
#include "Exceptions/Exceptions.h"

InternallyWeightedMatrix::InternallyWeightedMatrix(int matrixHeight, int matrixWidth,
                                                   int weightsHeight, int weightsWidth)
                       : Matrix(matrixHeight, matrixWidth),
                       weightsHeight(weightsHeight), weightsWidth(weightsWidth)
{
    weights = std::make_unique<Weights>(weightsHeight, weightsWidth);
}

void InternallyWeightedMatrix::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy,
                                       ConnectionsFactory &connectionsFactory, Container &precedingContainer) {
    try{
        for (int i = 0; i < this->neurons.size(); ++i) {
            auto connections = neuronsConnectingStrategy.proposeSingleNeuronConnections(i, *this, &precedingContainer);
            connectionsFactory.makeConnections(i, *this, connections);
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Internally Weighted Matrices requires Externally Weighted Neurons");
    }
}

Weight& InternallyWeightedMatrix::getWeight(int neuronIndex) {
    return weights->getWeight(neuronIndex);
}

