//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "ConvolutionLayer_.h"
#include "../../Exceptions/Exceptions.h"
#include "../../Containers/ContainersFactories/MatricesFactories/InternallyWeightedMatricesFactory.h"
#include "../../Containers/ContainersConnectingStrategy/ContainersConnecting1toRandom.h"
#include "../../Neurons/NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../Connections/ConnectionsFactories/ExternallyWeightedConnectionsFactory.h"


ConvolutionLayer_::ConvolutionLayer_(Layer* previousLayer, int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
        : Layer2D{
            previousLayer,
            numberOfFeatureDetectors,
            dynamic_cast<Layer2D&>(*previousLayer).getMatrixHeight() - (featureDetectorHeight / 2) * 2,
            dynamic_cast<Layer2D&>(*previousLayer).getMatrixWidth() - (featureDetectorWidth / 2) * 2},
        featureDetectorHeight{ featureDetectorHeight },
        featureDetectorWidth{ featureDetectorWidth }
{
    // suppress
    if(previousLayer == nullptr) throw LayerCreatingException("Cannot create Convolution Layer before any preceding layers");
}

void ConvolutionLayer_::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(
            *std::make_unique<InternallyWeightedMatricesFactory>(
                    matrixHeight,
                    matrixWidth,
                    featureDetectorHeight,
                    featureDetectorWidth
                ));
}

void ConvolutionLayer_::connect() {
    docker->createConnections(
                previousLayer->getDocker().get(),
                *std::make_unique<ContainersConnecting1toRandom>(),
                *std::make_unique<NeuronsConnecting1toArea>(featureDetectorHeight, featureDetectorWidth),
                *std::make_unique<ExternallyWeightedConnectionsFactory>()
            );
}

[[maybe_unused]] int ConvolutionLayer_::getFeatureDetectorHeight() const
{
    return featureDetectorHeight;
}

[[maybe_unused]] int ConvolutionLayer_::getFeatureDetectorWidth() const
{
    return featureDetectorWidth;
}

std::stringstream ConvolutionLayer_::getSummary()
{
    std::stringstream ss;
    ss << this << " " << getName() << "{ featureDetectorHeight: " << featureDetectorHeight
    << ", featureDetectorWidth: " << featureDetectorWidth << ", " << Layer2D::getSummary().str() << " }";
    return ss;
}

std::string ConvolutionLayer_::getName() {
    return "Convolution Layer";
}

