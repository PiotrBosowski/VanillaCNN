//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONVOLUTIONLAYER__H
#define VANILLACNN_CLION_CONVOLUTIONLAYER__H


#include "Layer2D.h"
#include <vector>
#include <memory>
#include <string>


class ConvolutionLayer_ : public Layer2D
{
public:
    ConvolutionLayer_(Layer* previousLayer, int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth);

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



#endif //VANILLACNN_CLION_CONVOLUTIONLAYER__H
