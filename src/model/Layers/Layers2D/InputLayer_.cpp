//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "InputLayer_.h"
#include "Exceptions/Exceptions.h"
#include "ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"

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
    throw LayersConnectingException("Cannot append Input Layer to any preceding layer");
}

std::stringstream InputLayer_::getSummary() {
    std::stringstream ss;
    ss << this << " "<< getName() << "{ " << Layer2D::getSummary().str() << " }";
    return ss;
}

std::string InputLayer_::getName() {
    return "Input Layer";
}



