//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers2D/ConvolutionLayer_.h>
#include "gtest/gtest.h"
#include "Layers/LayerPrototypes/ConvolutionLayer.h"
#include "Layers/Layers2D/InputLayer_.h"
#include "Containers/IInternallyWeightedContainer.h"

TEST(convolution_layer_prototype_check, initial_tests)
{
    //given
    int numberOfFeatureDetectors = 16;
    int inputH = 27;
    int inputW = 28;
    int featDetH = 7;
    int featDetW = 8;
    InputLayer_ previousLayer(inputH, inputW);
    ConvolutionLayer layer(numberOfFeatureDetectors, featDetH, featDetW);

    //when
    auto newLayer = layer.embodyLayer(&previousLayer);
    auto& newLayer_convol = dynamic_cast<ConvolutionLayer_&>(*newLayer);
    newLayer_convol.populate();

    //then
    ASSERT_EQ(newLayer_convol.getMatrixHeight(), 21);
    ASSERT_EQ(newLayer_convol.getMatrixWidth(), 21);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*newLayer->getDocker().getContainers()[0]).getWeightsHeight(), featDetH);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*newLayer->getDocker().getContainers()[0]).getWeightsWidth(), featDetW);
}