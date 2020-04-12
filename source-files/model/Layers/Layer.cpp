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

void Layer::setPreviousLayer(std::shared_ptr<Layer> previousLayer)
{
    this->previousLayer = previousLayer.get();
}

int Layer::getNumberOfContainers()
{
    return docker->size();
}

void Layer::connectToPreceding()
{
    docker->connectToPreceding(previousLayer);
}

std::string Layer::getSummary()
{
    return "Layer:\n";
}

std::vector<std::unique_ptr<Container>>& Layer::getContainers()
{
    return docker->getContainers();
}
