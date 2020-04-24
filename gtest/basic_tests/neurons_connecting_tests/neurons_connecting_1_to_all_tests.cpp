//
// Created by piotr on 20/04/23.
//

#include <Containers/Matrices/WeightlessMatrix.h>
#include "gtest/gtest.h"
#include "NeuronsConnecting/NeuronsConnecting1toAll.h"

TEST(neurons_connecting_1_to_all_check, basic_tests)
{
    //given
    WeightlessMatrix source(3, 3);
    WeightlessMatrix preceding(3,3);

    //when
    NeuronsConnecting1toAll strategy;
    for (int i = 0; i < source.getNumberOfNeurons(); ++i) {
        auto result = strategy.proposeSingleNeuronConnections(i, source, preceding);
        ASSERT_EQ(result.size(), preceding.getNumberOfNeurons());
        for (int j = 0; j < preceding.getNumberOfNeurons(); ++j) {
            ASSERT_EQ(result[j], &preceding.getNeuron(preceding.getHeightFromIndex(j), preceding.getWidthFromIndex(j)))
            << "index: " << j << ", height: " << preceding.getHeightFromIndex(j) << ", width: " << preceding.getWidthFromIndex(j);
        }
    }
}
