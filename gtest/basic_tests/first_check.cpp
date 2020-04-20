//
// Created by piotr on 20/04/20.
//

#include "Neurons/Neuron.h"
#include "gtest/gtest.h"

TEST(first_check, test_eq)
{
    EXPECT_EQ(1, 1);
}

TEST(first_check, test_neq)
{
    Neuron first;

    EXPECT_NE(1, 0);
}