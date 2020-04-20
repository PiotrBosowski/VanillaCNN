//
// Created by piotr on 20/04/11.
//

#include "DownsamplingLayer.h"
#include "Layers/Layers2D/DownsamplingLayer_.h"

DownsamplingLayer::DownsamplingLayer(int downsamplerHeight, int downsamplerWidth)
        : downsamplerHeight{ downsamplerHeight }, downsamplerWidth{ downsamplerWidth }
{
}

std::unique_ptr<Layer> DownsamplingLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<DownsamplingLayer_>(previousLayer, downsamplerHeight, downsamplerWidth);
}

std::string DownsamplingLayer::getName() {
    return "Downsampling Layer ";
}

std::stringstream DownsamplingLayer::getSummary() {
    std::stringstream ss;
    ss << getName() << "downsamplerHeight: " << downsamplerHeight
    << ", downsamplerWidth: " << downsamplerWidth;
    return ss;
}
