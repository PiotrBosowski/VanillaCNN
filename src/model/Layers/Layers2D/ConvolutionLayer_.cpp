//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "ConvolutionLayer_.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toRandom.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../exceptions/Exceptions.h"
#include "../../ContainersFactories/MatricesFactories/InternallyWeightedMatricesFactory.h"
#include "../../ConnectionsFactories/WeightlessConnectionsFactory.h"
#include "../../ConnectionsFactories/ExternallyWeightedConnectionsFactory.h"

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

int ConvolutionLayer_::getFeatureDetectorHeight()
{
    return featureDetectorHeight;
}

int ConvolutionLayer_::getFeatureDetectorWidth()
{
    return featureDetectorWidth;
}

std::string ConvolutionLayer_::getSummary()
{
    std::stringstream ss;
    ss << "Convolution Layer. Containers: "<< numberOfContainers << ", matrixH: " << this->matrixHeight << ", matrixW: "
    << this->matrixWidth << ", detectorH: " << this->featureDetectorHeight << ", detectorW: " << this->featureDetectorWidth << std::endl;
    //return ss.str() + Layer::getSummary(); TODO make getSummary recursive
    return ss.str();
}

