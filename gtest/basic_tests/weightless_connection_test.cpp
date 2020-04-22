//
// Created by piotr on 20/04/22.
//

#include "Connections/WeightlessConnection.h"
#include "gtest/gtest.h"
#include "Neurons/Neuron.h"

TEST(weightless_connection_test, initial_values_test)
{
    //given
    Neuron neuron;
    WeightlessConnection connection{neuron};

    //when
    auto weight = (double)connection.getWeight();

    //then
    ASSERT_NEAR(weight, 1.0, 0.001);
    ASSERT_EQ(&neuron, &connection.getNeuron());
}

TEST(weightless_connection_test, weight_change_test)
{
    //given
    Neuron neuron;
    WeightlessConnection first_conn{neuron};
    WeightlessConnection secnd_conn{neuron};

    //when
    auto& weight = first_conn.getWeight();
    weight = 10.0;

    //then
    ASSERT_NEAR((double)first_conn.getWeight(), 10.0, 0.001);
    ASSERT_NEAR((double)secnd_conn.getWeight(), 10.0, 0.001);
}

