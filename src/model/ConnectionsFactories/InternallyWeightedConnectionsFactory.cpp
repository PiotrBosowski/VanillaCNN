//
// Created by piotr on 20/04/16.
//

#include "InternallyWeightedConnectionsFactory.h"
#include "Containers/Matrices/WeightlessMatrix.h"
#include "Connections/InternallyWeightedConnection.h"


void InternallyWeightedConnectionsFactory::
makeConnections(int neuronIndex, Container &source, const std::vector<Neuron *> &connections)
{
    auto _ = dynamic_cast<IWeightlessContainer&>(source); //throws std::bad_cast if connecting to non WeightlessContainer
    for (auto& connection : connections)
    {
        source.getNeuron(neuronIndex).acceptConnection(std::make_unique<InternallyWeightedConnection>(*connection));
    }
}
