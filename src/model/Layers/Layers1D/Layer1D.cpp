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

std::stringstream Layer1D::getSummary() {
    std::stringstream ss;
    ss << Layer1D::getName() << "{ numberOfNeurons: " << numberOfNeurons << ", "<< Layer::getSummary().str() << " }";
    return ss;
}

std::string Layer1D::getName() {
    return "Layer1D";
}
