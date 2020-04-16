//
// Created by piotr on 20/04/11.
//



#include "ConvolutionLayer.h"
#include "../Layers2D/_ConvolutionLayer.h"

ConvolutionLayer::ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
        : numberOfFeatureDetectors{ numberOfFeatureDetectors }, featureDetectorHeight{ featureDetectorHeight }, featureDetectorWidth{ featureDetectorWidth }
{
}

std::unique_ptr<Layer> ConvolutionLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<_ConvolutionLayer>(previousLayer, numberOfFeatureDetectors, featureDetectorHeight, featureDetectorWidth);
}
