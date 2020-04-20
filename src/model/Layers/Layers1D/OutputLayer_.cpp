//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "OutputLayer_.h"
#include "Exceptions/Exceptions.h"
#include "ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "NeuronsConnections/NeuronsConnecting1toAll.h"
#include "ConnectionsFactories/InternallyWeightedConnectionsFactory.h"

OutputLayer_::OutputLayer_(Layer* previousLayer, int numberOfNeurons)
        : Layer1D{ previousLayer,
           1,
           numberOfNeurons }
{
    if(previousLayer == nullptr) throw LayerCreatingException("Cannot create Output Layer without any preceding layers");
}

void OutputLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessVectorsFactory>(numberOfNeurons));
}

void OutputLayer_::connect() {
    docker->createConnections(
            previousLayer->getDocker().get(),
            *std::make_unique<ContainersConnecting1toAll>(),
            *std::make_unique<NeuronsConnecting1toAll>(),
            *std::make_unique<InternallyWeightedConnectionsFactory>()
    );
}

std::stringstream OutputLayer_::getSummary()
{
    std::stringstream ss;
    ss << this << " "<< getName() << "{ " << Layer1D::getSummary().str() << " }";
    return ss;
}

std::string OutputLayer_::getName() {
    return "Output Layer";
}
