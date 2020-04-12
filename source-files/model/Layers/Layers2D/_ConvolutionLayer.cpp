//
// Created by piotr on 20/04/11.
//


#include "_ConvolutionLayer.h"
#include "../../ContainersConnectingStrategy/ContainersConnecting1toRandom.h"
#include "../../NeuronsConnections/NeuronsConnecting1toArea.h"
#include "../../enums/TBDMarkerEnum.h"
#include "../../exceptions/Exceptions.h"
#include "../../ContainersFactories/MatricesFactories/InternallyWeightedMatricesFactory.h"
#include "../../NeuronsFactories/ExternallyWeightedNeuronsFactory.h"

_ConvolutionLayer::_ConvolutionLayer(Layer* previousLayer, int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
        : Layer2D{ previousLayer,
                   previousLayer->getNumberOfContainers(),
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixHeight() - (featureDetectorHeight / 2) * 2,
                   dynamic_cast<Layer2D&>(*previousLayer).getMatrixWidth() - (featureDetectorWidth / 2) * 2},
          featureDetectorHeight{ featureDetectorHeight },
          featureDetectorWidth{ featureDetectorWidth }
{
    docker = std::make_unique<Docker>(
            *this,
        numberOfContainers,
        std::make_unique<InternallyWeightedMatricesFactory>(matrixHeight, matrixWidth, featureDetectorHeight, featureDetectorWidth),
        std::make_unique<ContainersConnecting1toRandom>(),
        std::make_unique<ExternallyWeightedNeuronsFactory>(),
        std::make_unique<NeuronsConnecting1toArea>(featureDetectorHeight, featureDetectorWidth)
    );
    connectToPreceding();
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
    std::string result = Layer2D::getSummary() + "\t\tConvolutionLayer: featureDetectorHeight(" + std::to_string(featureDetectorHeight)
                         + "), featureDetectorWidth(" + std::to_string(featureDetectorWidth) + ")\n";
    return result;
}

