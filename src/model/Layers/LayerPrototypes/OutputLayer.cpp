//
// Created by piotr on 20/04/11.
//

#include "OutputLayer.h"
#include "../Layers1D/OutputLayer_.h"

OutputLayer::OutputLayer(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
}

std::unique_ptr<Layer> OutputLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<OutputLayer_>(previousLayer, numberOfNeurons);
}

std::string OutputLayer::getName() {
    return "Output Layer ";
}

std::stringstream OutputLayer::getSummary() {
    std::stringstream ss;
    ss << getName() << "numberOfNeurons: " << numberOfNeurons;
    return ss;
}
