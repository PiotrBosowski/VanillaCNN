//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "_InputLayer.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnectingNone.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"
#include "../../NeuronsConnections/NeuronsConnectingError.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toRandom.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1to1.h"

_InputLayer::_InputLayer(int inputHeight, int inputWidth)
        : Layer2D{ nullptr,
                   1,
                   inputHeight,
                   inputWidth }
{
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(inputHeight, inputWidth),
                             *std::make_unique<WeightlessNeuronsFactory>());
    if(previousLayer)
        docker->createConnections(previousLayer->getDocker().get(),
                                  *std::make_unique<ContainersConnectingNone>(),
                                  *std::make_unique<NeuronsConnectingError>(),
                                          *std::make_unique<ConnectionsFactory>()
        );
}

std::string _InputLayer::getSummary() {
    std::stringstream ss;
    ss << "Input layer. Containers: "<< numberOfContainers << ", matrixH: " << matrixHeight << ", matrixW: " << matrixWidth << std::endl;
    return ss.str();
}

