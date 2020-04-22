//
// Created by piotr on 20/04/16.
//

#include "ExternallyWeightedConnectionsFactory.h"
#include "Containers/Matrices/InternallyWeightedMatrix.h"
#include "Connections/ExternallyWeightedConnection.h"


void ExternallyWeightedConnectionsFactory::makeConnections(int neuronIndex, Container &source,
                                                           const std::vector<Neuron *> &connections)
{
    auto& internallyWeightedContainer = dynamic_cast<IInternallyWeightedContainer&>(source);  //throws std::bad_cast if connecting to non InternallyWeightedContainer
    for (int j = 0; j < connections.size(); j++)
    {
        source.getNeuron(neuronIndex).
        acceptConnection(std::make_unique<ExternallyWeightedConnection>(*connections[j],
                internallyWeightedContainer.getWeight(j)));
    }
}
