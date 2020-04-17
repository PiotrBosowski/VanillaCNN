//
// Created by piotr on 20/04/16.
//

#include "ExternallyWeightedConnectionsFactory.h"
#include "../Neurons/ExternallyWeightedNeuron.h"
#include "../Containers/Matrices/InternallyWeightedMatrix.h"


void ExternallyWeightedConnectionsFactory::makeConnections(int neuronIndex, Container &source,
                                                           const std::vector<Neuron *> &connections)
{
    auto externallyWeightedNeuron = dynamic_cast<ExternallyWeightedNeuron*>(&source.getNeuron(neuronIndex));
//    auto externallyWeightedContainer = dynamic_cast<ExternallyWeightedContainer>(); //TODO INTERNALLY WEIGHTED INTERFACE
    auto externallyWeightedContainer = dynamic_cast<InternallyWeightedMatrix*>(&source);
    //requirements met otherwise std::bad_cast is thrown
    for (int j = 0; j < connections.size(); j++)
    {
        externallyWeightedNeuron->connect(*connections[j], externallyWeightedContainer->getWeight(j));
    }
}
