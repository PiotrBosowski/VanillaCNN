//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "DownsamplingLayer_.h"
#include "../../exceptions/Exceptions.h"
#include "../../Containers/ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../Containers/ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "../../Neurons/NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../Connections/ConnectionsFactories/WeightlessConnectionsFactory.h"

DownsamplingLayer_::DownsamplingLayer_(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth)
        : Layer2D{ previousLayer,
                   previousLayer->getNumberOfContainers(),
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixHeight() / downsamplerHeight,
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixWidth() / downsamplerWidth,
                   },
         downsamplerHeight(downsamplerHeight),
         downsamplerWidth(downsamplerWidth)
{
    if(previousLayer == nullptr) throw LayerCreatingException("Cannot create DownsamplingLayer before any preceeding layers");
}

void DownsamplingLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth));
}
void DownsamplingLayer_::connect() {
    docker->createConnections(
            previousLayer->getDocker().get(),
            *std::make_unique<ContainersConnecting1to1>(),
            *std::make_unique<NeuronsConnecting1toArea>(downsamplerHeight, downsamplerWidth),
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
