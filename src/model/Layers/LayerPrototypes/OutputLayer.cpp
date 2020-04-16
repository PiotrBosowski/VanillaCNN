//
// Created by piotr on 20/04/11.
//

#include "OutputLayer.h"
#include "../Layers1D/_OutputLayer.h"

OutputLayer::OutputLayer(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
}

std::unique_ptr<Layer> OutputLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<_OutputLayer>(previousLayer, numberOfNeurons);
}
