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
    return numberOfContainers;
}



const std::unique_ptr<Docker> &Layer::getDocker() const {
    return docker;
}
