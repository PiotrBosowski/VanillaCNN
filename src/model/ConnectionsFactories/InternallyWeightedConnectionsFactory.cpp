//
// Created by piotr on 20/04/16.
//

#include "InternallyWeightedConnectionsFactory.h"
#include "../Containers/Matrices/WeightlessMatrix.h"
#include "../Connection/InternallyWeightedConnection.h"


void InternallyWeightedConnectionsFactory::
makeConnections(int neuronIndex, Container &source, const std::vector<Neuron *> &connections)
{
    auto weightlessContainer = dynamic_cast<IWeightlessContainer*>(&source);
    //requirements met otherwise std::bad_cast is thrown
    for (auto& connection : connections)
    {
        source.getNeuron(neuronIndex).acceptConnection(std::make_unique<InternallyWeightedConnection>(*connection));
    }
}
