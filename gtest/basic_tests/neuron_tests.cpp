//
// Created by piotr on 20/04/20.
//

#include "gtest/gtest.h"
#include "Neurons/Neuron.h"

TEST(first_check, initial_value_test)
{
    for(int i = 0; i < 100; i++){
        Neuron current;
        EXPECT_NEAR(current.getValue(), 0.55, 0.45);
    }
}

TEST(first_check, test_neq)
{
    Neuron first;

    EXPECT_NE(1, 0);
}