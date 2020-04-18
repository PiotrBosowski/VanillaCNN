//
// Created by piotr on 20/04/11.
//



#include "ConvolutionLayer.h"
#include "../Layers2D/ConvolutionLayer_.h"

ConvolutionLayer::ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
        : numberOfFeatureDetectors{ numberOfFeatureDetectors }, featureDetectorHeight{ featureDetectorHeight }, featureDetectorWidth{ featureDetectorWidth }
{
}

std::unique_ptr<Layer> ConvolutionLayer::embodyLayer(Layer* previousLayer)
{
    return std::make_unique<ConvolutionLayer_>(previousLayer, numberOfFeatureDetectors, featureDetectorHeight, featureDetectorWidth);
}

std::stringstream ConvolutionLayer::getSummary() {
    std::stringstream ss;
    ss << getName() << "numberOfFeatureDetectors: " << numberOfFeatureDetectors
       << ", featureDetectorHeight: " << featureDetectorHeight
       << ", featureDetectorWidth: " << featureDetectorWidth;
    return ss;
}

std::string ConvolutionLayer::getName() {
    return "Convolution Layer ";
}