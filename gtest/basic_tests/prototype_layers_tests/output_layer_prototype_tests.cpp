//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers1D/OutputLayer_.h>
#include "Layers/LayerPrototypes/OutputLayer.h"
#include "Layers/Layers2D/InputLayer_.h"

#include "gtest/gtest.h"

TEST(output_layer_prototype_check, initial_tests)
{
    //given
    int numberOfFeatureDetectors = 16;
    int inputH = 21;
    int inputW = 24;
    int numberOfNeurons = 120;
    InputLayer_ previousLayer(inputH, inputW);
    previousLayer.populate();
    OutputLayer layer(numberOfNeurons);

    //when
    auto newLayer = layer.embodyLayer(&previousLayer);
    auto& dense = dynamic_cast<OutputLayer_&>(*newLayer);
    ASSERT_NE(newLayer, nullptr);
    dense.populate();
    dense.connect();

    //then
    ASSERT_EQ(dense.getNumberOfContainers(), 1);
    ASSERT_EQ(dense.getDocker().getContainers()[0]->getNumberOfNeurons(), numberOfNeurons);
    ASSERT_EQ(dense.getDocker().getContainers()[0]->getNeuron(0).getNumberOfConnections(), inputH*inputW);
}