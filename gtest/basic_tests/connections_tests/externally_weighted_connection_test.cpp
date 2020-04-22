//
// Created by piotr on 20/04/22.
//

#include "Connections/ExternallyWeightedConnection.h"
#include "gtest/gtest.h"
#include "Neurons/Neuron.h"

TEST(externally_weighted_connection_test, weight_change_test)
{
    //given
    Weight weight_first{2.0};
    Weight weight_secnd{5.0};
    Neuron neuron;
    ExternallyWeightedConnection connection_first{neuron, weight_first};
    ExternallyWeightedConnection connection_secnd{neuron, weight_secnd};

    //when
    weight_first = 50.0;
    weight_secnd = 100.0;

    //then
    ASSERT_NEAR((double)connection_first.getWeight(), 50.0, 0.001);
    ASSERT_NEAR((double)connection_secnd.getWeight(), 100.0, 0.001);
}
