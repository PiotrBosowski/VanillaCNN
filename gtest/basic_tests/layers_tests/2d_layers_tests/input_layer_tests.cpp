//
// Created by piotr on 20/04/23.
//

//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers1D/OutputLayer_.h>
#include <Layers/Layers2D/InputLayer_.h>
#include <Layers/Layers2D/DownsamplingLayer_.h>
#include "gtest/gtest.h"

TEST(input_layer_check, constructing_test)
{
    //given
    int inputH = 20, inputW = 24;

    //when
    auto previousLayer = InputLayer_(inputH, inputW);
    previousLayer.populate();

    //then
    ASSERT_EQ(previousLayer.getNumberOfContainers(), 1);
    ASSERT_EQ(previousLayer.getDocker().size(), 1);
    ASSERT_EQ(previousLayer.getMatrixHeight(), inputH);
    ASSERT_EQ(previousLayer.getMatrixWidth(), inputW);
}