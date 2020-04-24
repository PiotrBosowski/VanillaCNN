//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers1D/OutputLayer_.h>
#include <Layers/Layers2D/InputLayer_.h>
#include <Layers/Layers2D/ConvolutionLayer_.h>
#include <Layers/Layers2D/DownsamplingLayer_.h>
#include "gtest/gtest.h"
#include "Layers/Layers1D/FullyConnectedLayer_.h"

TEST(downsampling_layer_check, constructing_test)
{
    //given
    int inputH = 20, inputW = 24;
    int weightH = 4, weightW = 3;
    auto previousLayer = InputLayer_(inputH, inputW);
    previousLayer.populate();

    //when
    DownsamplingLayer_ down(&previousLayer, weightH, weightW);
    down.populate();
    down.connect();

    //then
    ASSERT_EQ(down.getNumberOfContainers(), 1);
    ASSERT_EQ(down.getDocker().size(), 1);
    ASSERT_EQ(down.getDownsamplerHeight(), weightH);
    ASSERT_EQ(down.getDownsamplerWidth(), weightW);
    ASSERT_EQ(down.getMatrixHeight(), inputH/weightH);
    ASSERT_EQ(down.getMatrixWidth(), inputW/weightW);
}

TEST(downsampling_layer_check, connecting_test)
{
    //given
    int numberOfNeurons = 80;
    auto inputLayer = InputLayer_(28, 28);
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
            DownsamplingLayer_ testingLayer(&second_fully, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            DownsamplingLayer_ testingLayer(&second_convo, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            DownsamplingLayer_ testingLayer(&second_downs, 2, 2);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            DownsamplingLayer_ testingLayer(&inputLayer, 2, 2);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_ANY_THROW(
            DownsamplingLayer_ testingLayer(&second_output, 3, 3);
            testingLayer.populate();
            testingLayer.connect();
    );
}
