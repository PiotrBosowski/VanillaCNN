//
// Created by piotr on 20/04/22.
//

#include "Connections/InternallyWeightedConnection.h"
#include "gtest/gtest.h"
#include "Neurons/Neuron.h"

TEST(internally_weighted_connection_test, weight_change_test)
{
    //given
    Neuron neuron;
    InternallyWeightedConnection first_conn{neuron};
    InternallyWeightedConnection secnd_conn{neuron};

    //when
    auto& weight_first = first_conn.getWeight();
    weight_first = 10.0;
    auto& weight_secnd = secnd_conn.getWeight();
    weight_secnd = 8.0;

    //then
    ASSERT_NEAR((double)first_conn.getWeight(), 10.0, 0.001);
    ASSERT_NEAR((double)secnd_conn.getWeight(), 8.0, 0.001);
}

