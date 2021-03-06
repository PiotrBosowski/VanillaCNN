//
// Created by piotr on 20/04/11.
//

#include "FullyConnectedLayer_.h"
#include "Exceptions/Exceptions.h"
#include "ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "NeuronsConnecting/NeuronsConnecting1toAll.h"
#include "ConnectionsFactories/InternallyWeightedConnectionsFactory.h"
#include <sstream>

FullyConnectedLayer_::FullyConnectedLayer_(Layer* previousLayer, int numberOfNeurons)
        : Layer1D{ previousLayer,
                   1,
                   numberOfNeurons }
{
    if(!dynamic_cast<Layer*>(previousLayer)) throw LayerCreatingException("Cannot create Fully Connected Layer without any preceding layers");
}

void FullyConnectedLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessVectorsFactory>(numberOfNeurons));
}

void FullyConnectedLayer_::connect() {
    docker->createConnections(
            previousLayer->getDocker(),
            *std::make_unique<ContainersConnecting1toAll>(),
            *std::make_unique<NeuronsConnecting1toAll>(),
            *std::make_unique<InternallyWeightedConnectionsFactory>()
    );
}

std::stringstream FullyConnectedLayer_::getSummary()
{
    std::stringstream ss;
    ss << this << " " << getName() << "{ " << Layer1D::getSummary().str() << " }";
    return ss;
}

std::string FullyConnectedLayer_::getName() {
    return "Fully Connected Layer";
}
