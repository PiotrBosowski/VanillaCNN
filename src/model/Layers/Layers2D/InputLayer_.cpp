//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "InputLayer_.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../exceptions/Exceptions.h"

InputLayer_::InputLayer_(int inputHeight, int inputWidth)
        : Layer2D{ nullptr,
                   1,
                   inputHeight,
                   inputWidth }
{
}

void InputLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth));
}

void InputLayer_::connect() {
    throw LayerConnectingError("Cannot append Input Layer to any preceding layer");
}

std::string InputLayer_::getSummary() {
    std::stringstream ss;
    ss << "Input layer. Containers: "<< numberOfContainers << ", matrixH: " << matrixHeight << ", matrixW: " << matrixWidth << std::endl;
    return ss.str();
}



