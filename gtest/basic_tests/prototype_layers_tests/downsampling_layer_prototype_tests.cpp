//
// Created by piotr on 20/04/23.
//

#include <Layers/Layers2D/DownsamplingLayer_.h>
#include "gtest/gtest.h"
#include "Layers/LayerPrototypes/DownsamplingLayer.h"
#include "Layers/Layers2D/InputLayer_.h"

TEST(downsampling_layer_prototype_check, initial_tests)
{
    //given
    int numberOfFeatureDetectors = 16;
    int inputH = 21;
    int inputW = 24;
    int downsamplerH = 11;
    int downsamplerW = 13;
    InputLayer_ previousLayer(inputH, inputW);
    DownsamplingLayer layer(downsamplerH, downsamplerW);

    //when
    auto newLayer = layer.embodyLayer(&previousLayer);
    auto& newLayer_downsampling = dynamic_cast<DownsamplingLayer_&>(*newLayer);
    ASSERT_NE(newLayer, nullptr);
    newLayer_downsampling.populate();

    //then
    ASSERT_EQ(newLayer_downsampling.getMatrixHeight(), inputH/downsamplerH);
    ASSERT_EQ(newLayer_downsampling.getMatrixWidth(), inputW/downsamplerW);
}