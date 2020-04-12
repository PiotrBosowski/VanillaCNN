//
// Created by piotr on 20/04/11.
//


#include "Layer1D.h"

Layer1D::Layer1D(Layer* previousLayer,
                 int numberOfContainers,
                 int numberOfNeurons)
        : Layer{ previousLayer, numberOfContainers},
          numberOfNeurons{numberOfNeurons}
{
}

std::string Layer1D::getSummary()
{
    std::string result = Layer::getSummary() + "\tLayer1D: numberOfNeurons(" + std::to_string(numberOfNeurons) + ")\n";
    return result;
}