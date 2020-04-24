//
// Created by piotr on 20/04/11.
//

#include "WeightlessMatrix.h"
#include "Exceptions/Exceptions.h"

WeightlessMatrix::WeightlessMatrix(int matrixHeight, int matrixWidth)
    : Matrix(matrixHeight, matrixWidth) {}

void
WeightlessMatrix::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                          Container &precedingContainer) {
    try{
        for (int i = 0; i < this->neurons.size(); ++i) {
            auto connections = neuronsConnectingStrategy.proposeSingleNeuronConnections(i, *this, precedingContainer);
            connectionsFactory.makeConnections(i, *this, connections);
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Weightless Matrix can only be used with Weightless Neurons");
    }
}
