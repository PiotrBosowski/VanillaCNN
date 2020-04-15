//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__CONVOLUTIONLAYER_H
#define VANILLACNN_CLION__CONVOLUTIONLAYER_H


#include "Layer2D.h"
#include <vector>
#include <memory>
#include <string>


class _ConvolutionLayer : public Layer2D
{
public:
    _ConvolutionLayer(Layer* previousLayer, int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth);

private:
    int featureDetectorHeight;
    int featureDetectorWidth;
public:
    int getFeatureDetectorHeight();
    int getFeatureDetectorWidth();

    void connect() override;

    void populate() override;

    std::string getSummary() override;
};



#endif //VANILLACNN_CLION__CONVOLUTIONLAYER_H
