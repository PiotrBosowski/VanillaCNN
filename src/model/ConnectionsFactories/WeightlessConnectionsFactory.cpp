//
// Created by piotr on 20/04/12.
//

#include <Containers/IWeightlessContainer.h>
#include "WeightlessConnectionsFactory.h"
#include "Connections/WeightlessConnection.h"
#include "Neurons/Neuron.h"

void WeightlessConnectionsFactory::makeConnections(int neuronIndex, Container &source,
                                                   const std::vector<Neuron *> &connections) {
    auto _ = dynamic_cast<IWeightlessContainer&>(source); //throws std::bad_cast if connecting to non WeightlessContainer
    for (auto& connection : connections)
    {
        source.getNeuron(neuronIndex).acceptConnection(std::make_unique<WeightlessConnection>(*connection));
    }
}
