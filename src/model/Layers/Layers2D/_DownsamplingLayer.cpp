//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "_DownsamplingLayer.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "../../NeuronsFactories/WeightlessNeuronsFactory.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../exceptions/Exceptions.h"
#include "../../ConnectionsFactories/WeightlessConnectionsFactory.h"

_DownsamplingLayer::_DownsamplingLayer(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth)
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

void _DownsamplingLayer::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<WeightlessMatricesFactory>(matrixHeight, matrixWidth),
                             *std::make_unique<WeightlessNeuronsFactory>());
}
void _DownsamplingLayer::connect() {
    docker->createConnections(
            previousLayer->getDocker().get(),
            *std::make_unique<ContainersConnecting1to1>(),
            *std::make_unique<NeuronsConnecting1toArea>(downsamplerHeight, downsamplerWidth),
            *std::make_unique<WeightlessConnectionsFactory>()
    );
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
    std::stringstream ss;
    ss << "Downsampling Layer. Containers: "<< numberOfContainers << ", matrixH: "
    << this->matrixHeight << ", matrixW: " << this->matrixWidth << ", downsamplerH: " << this->downsamplerHeight << ", downsamplerW: " << downsamplerWidth << std::endl;
    return ss.str();
}
