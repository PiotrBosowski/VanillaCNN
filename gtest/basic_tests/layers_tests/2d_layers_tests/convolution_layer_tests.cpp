//
// Created by piotr on 20/04/23.
//

//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers1D/OutputLayer_.h>
#include <Layers/Layers2D/InputLayer_.h>
#include <Layers/Layers2D/ConvolutionLayer_.h>
#include <Layers/Layers2D/DownsamplingLayer_.h>
#include "gtest/gtest.h"
#include "Layers/Layers1D/FullyConnectedLayer_.h"
#include "Containers/IInternallyWeightedContainer.h"

TEST(convolution_layer_check, constructing_test)
{
    //given
    int inputH = 20, inputW = 24;
    int weightH = 4, weightW = 3;
    int numberOfFeatureDets = 6;
    auto previousLayer = InputLayer_(inputH, inputW);
    previousLayer.populate();

    //when
    ConvolutionLayer_ convo(&previousLayer, numberOfFeatureDets, weightH, weightW);
    convo.populate();
    convo.connect();

    //then
    ASSERT_EQ(convo.getNumberOfContainers(), numberOfFeatureDets);
    ASSERT_EQ(convo.getDocker().size(), numberOfFeatureDets);
    ASSERT_EQ(convo.getFeatureDetectorHeight(), weightH);
    ASSERT_EQ(convo.getFeatureDetectorWidth(), weightW);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*convo.getDocker().getContainers()[0]).getWeightsHeight(), weightH);
    ASSERT_EQ(dynamic_cast<IInternallyWeightedContainer&>(*convo.getDocker().getContainers()[0]).getWeightsWidth(), weightW);
    ASSERT_EQ(convo.getMatrixHeight(), inputH - weightH + 1);
    ASSERT_EQ(convo.getMatrixWidth(), inputW - weightW + 1);
}

TEST(convolution_layer_check, connecting_test)
{
    //given
    int numberOfNeurons = 80;
    auto inputLayer = InputLayer_(20, 30);
    inputLayer.populate();

    auto second_fully = FullyConnectedLayer_(&inputLayer, numberOfNeurons);
    second_fully.populate();
    auto second_convo = ConvolutionLayer_(&inputLayer, 6, 5, 5);
    second_convo.populate();
    auto second_downs = DownsamplingLayer_(&second_convo, 3, 3);
    second_downs.populate();
    auto second_output = OutputLayer_(&inputLayer, numberOfNeurons);
    second_output.populate();

    //when then
    ASSERT_ANY_THROW(
            ConvolutionLayer_ testingLayer(&second_fully, 6, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            ConvolutionLayer_ testingLayer(&second_convo, 6, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            ConvolutionLayer_ testingLayer(&second_downs, 6, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            ConvolutionLayer_ testingLayer(&inputLayer, 6, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_ANY_THROW(
            ConvolutionLayer_ testingLayer(&second_output, 6, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
}
