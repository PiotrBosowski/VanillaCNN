//
// Created by piotr on 20/04/11.
//


#include <iostream>
#include "Layer.h"

Layer::Layer(Layer* previousLayer,
             int numberOfContainers)
        : previousLayer(previousLayer), numberOfContainers(numberOfContainers)
{
}

int Layer::getNumberOfContainers() const
{
    return numberOfContainers;
}

const std::unique_ptr<Docker> &Layer::getDocker() const {
    return docker;
}

std::stringstream Layer::getSummary() {
    std::stringstream ss;
    ss << Layer::getName() << "{ numberOfContainers: " << numberOfContainers << ", previousLayer: " << previousLayer << " }";
    return ss;
}

std::string Layer::getName() {
    return "Layer";
}
