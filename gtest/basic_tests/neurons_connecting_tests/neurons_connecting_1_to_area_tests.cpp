//
// Created by piotr on 20/04/23.
//

#include <Containers/Matrices/WeightlessMatrix.h>
#include "gtest/gtest.h"
#include "NeuronsConnecting/NeuronsConnecting1toArea.h"

TEST(neurons_connecting_1_to_area_check, basic_tests)
{
    //given
    int areaH = 4, areaW = 4;
    WeightlessMatrix source(5, 5);
    WeightlessMatrix preceding(20,20);
    NeuronsConnecting1toArea strategy(areaH, areaW, areaH, areaW);

    //when
    ASSERT_EQ(5, source.getMatrixHeight());
    ASSERT_EQ(5, source.getMatrixWidth());

    int source_neuron_counter = 0;
    for (int baseH = 0; baseH < source.getMatrixHeight(); ++baseH) {
        for (int baseW = 0; baseW < source.getMatrixWidth(); ++baseW) {
            auto result = strategy.proposeSingleNeuronConnections(source_neuron_counter, source, preceding);
            ASSERT_EQ(result.size(), areaH * areaW);
            int result_index = 0;
            for (int h = 0; h < areaH; ++h) {
                for (int w = 0; w < areaW; ++w) {
                    ASSERT_EQ(result[result_index], &preceding.getNeuron(baseH * areaH + h, baseW * areaW + w))
                    << "index: " << result_index << ", height: " << baseH * areaH + h << ", width: " << baseW * areaW + w;
                    result_index++;
                }
            }
            source_neuron_counter++;
        }
    }
}
