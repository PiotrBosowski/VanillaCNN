//
// Created by piotr on 20/04/23.
//

#include "gtest/gtest.h"
#include "Layers/LayerPrototypes/ConvolutionLayer.h"
#include "Layers/Layers2D/InputLayer_.h"
#include "Containers/IInternallyWeightedContainer.h"

TEST(convolution_layer_prototype_check, initial_tests)
{
    //given
    int numberOfFeatureDetectors = 16;
    int inputH = 21;
    int inputW = 24;
    int featDetH = 11;
    int featDetW = 13;
    InputLayer_ previousLayer(inputH, inputW);
    ConvolutionLayer layer(numberOfFeatureDetectors, featDetH, featDetW);

    //when
    auto newLayer = layer.embodyLayer(static_cast<Layer*>(&previousLayer));
    newLayer->populate();

    //then
    ASSERT_EQ(dynamic_cast<Layer2D&>(*newLayer).getMatrixHeight(), inputH - (featDetH/2)*2);
    ASSERT_EQ(dynamic_cast<Layer2D&>(*newLayer).getMatrixWidth(), inputW - (featDetW/2)*2);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*newLayer->getDocker()->getContainers()[0]).getWeightsHeight(), featDetH);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*newLayer->getDocker()->getContainers()[0]).getWeightsWidth(), featDetW);
}