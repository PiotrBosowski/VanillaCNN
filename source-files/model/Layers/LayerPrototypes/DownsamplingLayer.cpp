//
// Created by piotr on 20/04/11.
//

#include "DownsamplingLayer.h"
#include "../Layers2D/_DownsamplingLayer.h"

DownsamplingLayer::DownsamplingLayer(int downsamplerHeight, int downsamplerWidth)
        : downsamplerHeight{ downsamplerHeight }, downsamplerWidth{ downsamplerWidth }
{
}

std::unique_ptr<Layer> DownsamplingLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<_DownsamplingLayer>(previousLayer, downsamplerHeight, downsamplerWidth);
}
