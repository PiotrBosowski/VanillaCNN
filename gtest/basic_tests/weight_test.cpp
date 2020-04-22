//
// Created by piotr on 20/04/21.
//

#include <Weights/Weight.h>
#include "gtest/gtest.h"

TEST(weight_check, initial_value_test)
{
    for(unsigned long i = 0; i < 1000; i++){
        Weight current;
        ASSERT_GT(double(current), 0.10) << "weight smaller than 0.1";
        ASSERT_LE(double(current), 1.00) << "weight larger than 1.0";
    }
}
