//
// Created by piotr on 20/04/11.
//

#include "_FullyConnectedLayer.h"
#include "../../ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "../../NeuronsConnections/NeuronsConnecting1toAll.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"
#include "../../exceptions/Exceptions.h"
#include "../../ConnectionsFactories/InternallyWeightedConnectionsFactory.h"
#include <sstream>

_FullyConnectedLayer::_FullyConnectedLayer(Layer* previousLayer, int numberOfNeurons)
        : Layer1D{ previousLayer,
                   1,
                   numberOfNeurons }
{
    if(previousLayer == nullptr) throw LayerCreatingException("Cannot create Fully Connected Layer without any preceding layers");
}

void _FullyConnectedLayer::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessVectorsFactory>(numberOfNeurons),
                             *std::make_unique<WeightlessNeuronsFactory>());
}

void _FullyConnectedLayer::connect() {
    docker->createConnections(
            previousLayer->getDocker().get(),
            *std::make_unique<ContainersConnecting1toAll>(),
            *std::make_unique<NeuronsConnecting1toAll>(),
            *std::make_unique<InternallyWeightedConnectionsFactory>()
    );
}

std::string _FullyConnectedLayer::getSummary()
{
    std::stringstream ss;
    ss << "Fully Connected Layer. Containers: "<< numberOfContainers << ", neurons: " << this->numberOfNeurons << std::endl;
    return ss.str();
}
