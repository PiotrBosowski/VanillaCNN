//
// Created by piotr on 20/04/11.
//


#include "InputLayer.h"
#include "../Layers2D/InputLayer_.h"

InputLayer::InputLayer(int inputHeight, int inputWidth)
        : inputHeight{ inputHeight }, inputWidth{ inputWidth }
{
}

std::unique_ptr<Layer> InputLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<InputLayer_>(inputHeight, inputWidth);
}
