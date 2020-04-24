//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers2D/InputLayer_.h>
#include "Layers/LayerPrototypes/InputLayer.h"

#include "gtest/gtest.h"

TEST(input_layer_prototype_check, initial_tests)
{
    //given
    int inputH = 35;
    int inputW = 52;
    InputLayer layer(inputH, inputW);

    //when
    auto temp = layer.embodyLayer(nullptr);
    auto& input = dynamic_cast<InputLayer_&>(*temp);
    ASSERT_NE(temp, nullptr);
    input.populate();
    ASSERT_ANY_THROW(input.connect(););

    //then
    ASSERT_EQ(input.getNumberOfContainers(), 1);
    ASSERT_EQ(input.getDocker().getContainers()[0]->getNumberOfNeurons(), inputH*inputW);
    ASSERT_EQ(input.getDocker().getContainers()[0]->getNeuron(0).getNumberOfConnections(), 0);
}