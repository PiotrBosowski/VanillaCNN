//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "DownsamplingLayer_.h"
#include "Exceptions/Exceptions.h"
#include "ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "NeuronsConnecting/NeuronsConnecting1toArea.h"
#include "ConnectionsFactories/WeightlessConnectionsFactory.h"


DownsamplingLayer_::DownsamplingLayer_(Layer *previousLayer, int downsamplerHeight, int downsamplerWidth, int strideH, int strideW)
        : Layer2D{ previousLayer,
                   previousLayer->getNumberOfContainers(),
                   (dynamic_cast<Layer2D&>(*previousLayer).getMatrixHeight() - downsamplerHeight)/strideH + 1,
                   (dynamic_cast<Layer2D&>(*previousLayer).getMatrixWidth() - downsamplerWidth)/strideW + 1,
},
          downsamplerHeight(downsamplerHeight),
          downsamplerWidth(downsamplerWidth),
          strideH{strideH},
          strideW{strideW}
{
    if(previousLayer == nullptr) throw LayerCreatingException("Cannot create DownsamplingLayer before any preceeding layers");
}

DownsamplingLayer_::DownsamplingLayer_(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth) // deleting constructor. woah thats cool af
: DownsamplingLayer_(previousLayer, downsamplerHeight, downsamplerWidth, downsamplerHeight, downsamplerWidth)
{}

void DownsamplingLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth));
}
void DownsamplingLayer_::connect() {
    docker->createConnections(
            previousLayer->getDocker(),
            *std::make_unique<ContainersConnecting1to1>(),
            *std::make_unique<NeuronsConnecting1toArea>(downsamplerHeight, downsamplerWidth, downsamplerHeight, downsamplerWidth),
            *std::make_unique<WeightlessConnectionsFactory>()
    );
}

int DownsamplingLayer_::getDownsamplerHeight()
{
    return downsamplerHeight;
}

int DownsamplingLayer_::getDownsamplerWidth()
{
    return downsamplerWidth;
}

std::stringstream DownsamplingLayer_::getSummary()
{
    std::stringstream ss;
    ss << this << " "<< getName() << "{ downsamplerHeight: " << matrixHeight
       << ", downsamplerWidth: " << matrixWidth << ", " << Layer2D::getSummary().str() << " }";
    return ss;
}

std::string DownsamplingLayer_::getName() {
    return "Downsampling Layer";
}
