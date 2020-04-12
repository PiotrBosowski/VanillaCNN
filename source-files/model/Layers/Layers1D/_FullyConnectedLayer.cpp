//
// Created by piotr on 20/04/11.
//

#include "_FullyConnectedLayer.h"
#include "../../ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "../../NeuronsConnections/NeuronsConnecting1toAll.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"

_FullyConnectedLayer::_FullyConnectedLayer(Layer* previousLayer, int numberOfNeurons)
        : Layer1D{ previousLayer,
                   1,
                   numberOfNeurons }
{
    docker = std::make_unique<Docker>(
            *this,
            numberOfContainers,
            std::make_unique<WeightlessVectorsFactory>(numberOfNeurons),
            std::make_unique<ContainersConnecting1toAll>(),
            std::make_unique<WeightlessNeuronsFactory>(),
            std::make_unique<NeuronsConnecting1toAll>()
    );
    connectToPreceding();
}

std::string _FullyConnectedLayer::getSummary()
{
    std::string result = Layer1D::getSummary() + "\t\tFullyConnectedLayer\n";
    return result;
}
