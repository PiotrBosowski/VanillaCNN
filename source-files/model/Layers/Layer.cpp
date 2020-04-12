//
// Created by piotr on 20/04/11.
//


#include <iostream>
#include "../ContainersFactories/ContainersFactory.h"
#include "Layer.h"

Layer::Layer(Layer* previousLayer,
             int numberOfContainers)
        : previousLayer(previousLayer), numberOfContainers(numberOfContainers)
{
}

int Layer::getNumberOfContainers()
{
    return docker->size();
}

const std::vector<std::unique_ptr<Container>>& Layer::getContainers()
{
    return docker->getContainers();
}

Layer *Layer::getPreviousLayer() {
    return previousLayer;
}

const std::unique_ptr<Docker> &Layer::getDocker() const {
    return docker;
}
