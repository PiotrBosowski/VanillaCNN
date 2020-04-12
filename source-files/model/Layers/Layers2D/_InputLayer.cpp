//
// Created by piotr on 20/04/11.
//


#include "_InputLayer.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnectingError.h"
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
    docker = std::make_unique<Docker>(
        *this,
        1,
        std::make_unique<WeightlessMatricesFactory>(inputHeight, inputWidth),
        std::make_unique<ContainersConnectingError>(),
        std::make_unique<WeightlessNeuronsFactory>(),
        std::make_unique<NeuronsConnectingError>()
    );
}

std::string _InputLayer::getSummary()
{
    std::string result = Layer2D::getSummary() + "\t\tInputLayer\n";
    return result;
}
