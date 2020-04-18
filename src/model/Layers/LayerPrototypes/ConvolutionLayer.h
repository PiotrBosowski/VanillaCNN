//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONVOLUTIONLAYER_H
#define VANILLACNN_CLION_CONVOLUTIONLAYER_H


#include "PrototypeLayer.h"

class ConvolutionLayer : public PrototypeLayer
{
public:
    ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth);
    std::unique_ptr<Layer> embodyLayer(Layer* previousLayer) override;

    std::string getName() override;

    std::stringstream getSummary() override;

private:
    int numberOfFeatureDetectors;
    int featureDetectorHeight;
    int featureDetectorWidth;
};



#endif //VANILLACNN_CLION_CONVOLUTIONLAYER_H
