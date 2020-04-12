//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "_OutputLayer.h"
#include "../../ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "../../NeuronsFactories/ExternallyWeightedNeuronsFactory.h"
#include "../../NeuronsConnections/NeuronsConnecting1toAll.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"

_OutputLayer::_OutputLayer(Layer* previousLayer, int numberOfNeurons)
        : Layer1D{ previousLayer,
           1,
           numberOfNeurons }
{
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessVectorsFactory>(numberOfNeurons),
                             *std::make_unique<WeightlessNeuronsFactory>());

    if(previousLayer)
        docker->createConnections(previousLayer->getDocker().get(),
                                  *std::make_unique<ContainersConnecting1toAll>(),
                                  *std::make_unique<NeuronsConnecting1toAll>(),
                                  *std::make_unique<ConnectionsFactory>()
        );

}

std::string _OutputLayer::getSummary()
{
    std::stringstream ss;
    ss << "Output Layer. Containers: "<< numberOfContainers << ", neurons: " << this->numberOfNeurons << std::endl;
    return ss.str();
}