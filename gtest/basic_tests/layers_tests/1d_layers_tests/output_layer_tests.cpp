//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers1D/OutputLayer_.h>
#include <Layers/Layers2D/InputLayer_.h>
#include <Layers/Layers2D/ConvolutionLayer_.h>
#include <Layers/Layers2D/DownsamplingLayer_.h>
#include "gtest/gtest.h"
#include "Layers/Layers1D/FullyConnectedLayer_.h"

TEST(fully_connected_layer_check, constructing_test)
{
    //given
    int numberOfNeurons = 10;
    auto previousLayer = InputLayer_(20, 30);
    previousLayer.populate();

    //when
    OutputLayer_ dense(&previousLayer, numberOfNeurons);
    dense.populate();
    dense.connect();

    //then
    ASSERT_EQ(dense.getNumberOfContainers(), 1);
    ASSERT_EQ(dense.getDocker().size(), 1);
    ASSERT_EQ(dense.getDocker().getContainers()[0]->getNumberOfNeurons(), numberOfNeurons);
}

TEST(fully_connected_layer_check, connecting_test_positive)
{
    //given
    int numberOfNeurons = 80;
    auto inputLayer = InputLayer_(20, 30);
    inputLayer.populate();

    auto second_fully = FullyConnectedLayer_(&inputLayer, numberOfNeurons);
    second_fully.populate();
    auto second_convo = ConvolutionLayer_(&inputLayer, 6, 5, 5);
    second_convo.populate();
    auto second_downs = DownsamplingLayer_(&second_convo, 7, 7);
    second_downs.populate();
    auto second_output = OutputLayer_(&inputLayer, numberOfNeurons);
    second_output.populate();

    //when then
    ASSERT_NO_THROW(
            OutputLayer_ testingLayer(&second_fully, 80);
            testingLayer.populate();
            testingLayer.connect();

    );
    ASSERT_NO_THROW(
            OutputLayer_ testingLayer(&second_convo, 80);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            OutputLayer_ testingLayer(&second_downs, 80);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            OutputLayer_ testingLayer(&inputLayer, 80);
            testingLayer.populate();
            testingLayer.connect();
    );
    ASSERT_NO_THROW(
            OutputLayer_ testingLayer(&second_output, 80);
            testingLayer.populate();
            testingLayer.connect();
    );
}
