//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "_InputLayer.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"
#include "../../exceptions/Exceptions.h"

_InputLayer::_InputLayer(int inputHeight, int inputWidth)
        : Layer2D{ nullptr,
                   1,
                   inputHeight,
                   inputWidth }
{
}

void _InputLayer::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth),
                             *std::make_unique<WeightlessNeuronsFactory>());
}

void _InputLayer::connect() {
    throw LayerConnectingError("Cannot append Input Layer to any preceding layer");
}

std::string _InputLayer::getSummary() {
    std::stringstream ss;
    ss << "Input layer. Containers: "<< numberOfContainers << ", matrixH: " << matrixHeight << ", matrixW: " << matrixWidth << std::endl;
    return ss.str();
}



