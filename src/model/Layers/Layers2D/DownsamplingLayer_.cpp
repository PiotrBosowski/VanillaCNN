//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "DownsamplingLayer_.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "../../ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "../../exceptions/Exceptions.h"
#include "../../ConnectionsFactories/WeightlessConnectionsFactory.h"

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

std::string DownsamplingLayer_::getSummary()
{
    std::stringstream ss;
    ss << "Downsampling Layer. Containers: "<< numberOfContainers << ", matrixH: "
    << this->matrixHeight << ", matrixW: " << this->matrixWidth << ", downsamplerH: " << this->downsamplerHeight << ", downsamplerW: " << downsamplerWidth << std::endl;
    return ss.str();
}
