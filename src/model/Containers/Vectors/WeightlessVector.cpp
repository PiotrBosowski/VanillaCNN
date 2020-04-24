//
// Created by piotr on 20/04/11.
//

#include "Vector.h"
#include "WeightlessVector.h"
#include "Exceptions/Exceptions.h"

WeightlessVector::WeightlessVector(int vectorHeight)
: Vector(vectorHeight)
{
    if(vectorHeight < 0) throw ContainersCreatingException("cant create vector with negative number of neurons");
}

void
WeightlessVector::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                          Container &precedingContainer) {
    try {
        for (int i = 0; i < this->neurons.size(); ++i) {
            auto connections = neuronsConnectingStrategy.proposeSingleNeuronConnections(i, *this, precedingContainer);
            connectionsFactory.makeConnections(i, *this, connections);
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Weightless Vector can only be used with Weightless Neurons");
    }
}
