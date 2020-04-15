//
// Created by piotr on 20/04/11.
//

#include <sstream>
#include "_ConvolutionLayer.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toRandom.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../exceptions/Exceptions.h"
#include "../../ContainersFactories/MatricesFactories/InternallyWeightedMatricesFactory.h"
#include "../../NeuronsFactories/ExternallyWeightedNeuronsFactory.h"
#include "../../ConnectionsFactories/WeightlessConnectionsFactory.h"

_ConvolutionLayer::_ConvolutionLayer(Layer* previousLayer, int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
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

void _ConvolutionLayer::populate() {
    docker = std::make_unique<Docker>(numberOfContainers);
    docker->createContainers(*std::make_unique<InternallyWeightedMatricesFactory>(
            matrixHeight, matrixWidth, featureDetectorHeight, featureDetectorWidth),
                             *std::make_unique<ExternallyWeightedNeuronsFactory>());
}

void _ConvolutionLayer::connect() {
    docker->createConnections(previousLayer->getDocker().get(),
                              *std::make_unique<ContainersConnecting1toRandom>(),
                              *std::make_unique<NeuronsConnecting1toArea>(featureDetectorHeight, featureDetectorWidth),
                              *std::make_unique<ConnectionsFactory>()
    );
}

int _ConvolutionLayer::getFeatureDetectorHeight()
{
    return featureDetectorHeight;
}

int _ConvolutionLayer::getFeatureDetectorWidth()
{
    return featureDetectorWidth;
}

std::string _ConvolutionLayer::getSummary()
{
    std::stringstream ss;
    ss << "Convolution Layer. Containers: "<< numberOfContainers << ", matrixH: " << this->matrixHeight << ", matrixW: "
    << this->matrixWidth << ", detectorH: " << this->featureDetectorHeight << ", detectorW: " << this->featureDetectorWidth << std::endl;
    //return ss.str() + Layer::getSummary(); TODO
    return ss.str();
}

