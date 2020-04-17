//
// Created by piotr on 20/04/16.
//

#include "ExternallyWeightedConnectionsFactory.h"
#include "../Neurons/ExternallyWeightedNeuron.h"
#include "../Containers/Matrices/InternallyWeightedMatrix.h"
#include "../Connection/ExternallyWeightedConnection.h"


void ExternallyWeightedConnectionsFactory::makeConnections(int neuronIndex, Container &source,
                                                           const std::vector<Neuron *> &connections)
{
    auto externallyWeightedNeuron = dynamic_cast<ExternallyWeightedNeuron*>(&source.getNeuron(neuronIndex));
    auto internallyWeightedContainer = dynamic_cast<IInternallyWeightedContainer*>(&source);
    //requirements met otherwise std::bad_cast is thrown
    for (int j = 0; j < connections.size(); j++)
    {
        externallyWeightedNeuron->
        acceptConnection(std::make_unique<ExternallyWeightedConnection>(*connections[j],
                internallyWeightedContainer->getWeight(j)));
    }
}
