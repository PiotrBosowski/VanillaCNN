//
// Created by piotr on 20/04/11.
//

#include "../../NeuronsFactories/NeuronsFactory.h"
#include "Vector.h"
#include "WeightlessVector.h"
#include "../../exceptions/Exceptions.h"

WeightlessVector::WeightlessVector(NeuronsFactory &neuronFactory, int vectorHeight)
: Vector(neuronFactory, vectorHeight) {}

void
WeightlessVector::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                          Container &precedingContainer) {
    try {
        for (int i = 0; i < this->neurons.size(); ++i) {
            auto connections = neuronsConnectingStrategy.proposeSingleNeuronConnections(i, *this, &precedingContainer);
            connectionsFactory.makeConnections(i, *this, connections);
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Weightless Vector can only be used with Weightless Neurons");
    }
}
