//
// Created by piotr on 20/04/11.
//


#include "_DownsamplingLayer.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"

_DownsamplingLayer::_DownsamplingLayer(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth)
        : Layer2D{ previousLayer,
                   previousLayer->getNumberOfContainers(),
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixHeight() / downsamplerHeight,
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixWidth() / downsamplerWidth,
                   },
         downsamplerHeight(downsamplerHeight),
         downsamplerWidth(downsamplerWidth)
{
    docker = std::make_unique<Docker>(
            *this,
        numberOfContainers,
        std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth),
        std::make_unique<ContainersConnecting1to1>(),
        std::make_unique<WeightlessNeuronsFactory>(),
        std::make_unique<NeuronsConnecting1toArea>(downsamplerHeight, downsamplerWidth)
    );
    connectToPreceding();
}

int _DownsamplingLayer::getDownsamplerHeight()
{
    return downsamplerHeight;
}

int _DownsamplingLayer::getDownsamplerWidth()
{
    return downsamplerWidth;
}

std::string _DownsamplingLayer::getSummary()
{
    std::string result = Layer2D::getSummary() + "\t\tDownsamplingLayer: downsamplerHeight(" + std::to_string(downsamplerHeight)
                         + "), downsamplerWidth(" + std::to_string(downsamplerWidth) + ")\n";
    return result;
}
