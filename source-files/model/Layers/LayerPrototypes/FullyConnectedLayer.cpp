//
// Created by piotr on 20/04/11.
//


#include "FullyConnectedLayer.h"
#include "../Layers1D/_FullyConnectedLayer.h"

FullyConnectedLayer::FullyConnectedLayer(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
}

std::unique_ptr<Layer> FullyConnectedLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<_FullyConnectedLayer>(previousLayer, numberOfNeurons);
}
