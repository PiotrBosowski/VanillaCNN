//
// Created by piotr on 20/04/16.
//

#include "InternallyWeightedConnectionsFactory.h"
#include "../Neurons/WeightlessNeuron.h"
#include "../Containers/Matrices/WeightlessMatrix.h"

void InternallyWeightedConnectionsFactory::makeConnections(int neuronIndex, Container &source,
                                                           const std::vector<Neuron *> &connections) {
    auto weightlessNeuron = dynamic_cast<WeightlessNeuron*>(&source.getNeuron(neuronIndex));
//    auto externallyWeightedContainer = dynamic_cast<ExternallyWeightedContainer>(); //TODO INTERNALLY WEIGHTED INTERFACE
    auto weightlessMatrix = dynamic_cast<WeightlessMatrix*>(&source); //TODO SAME AS ABOVE - APPLICABLE TO MATRICES AND VECTORS
    //requirements met otherwise std::bad_cast is thrown
    for (auto connection : connections)
    {
        weightlessNeuron->connect(*connection);
    }
}
// TODO Container2D interface