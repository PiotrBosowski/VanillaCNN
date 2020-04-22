//
// Created by piotr on 20/04/21.
//

#include <Weights/Weights.h>
#include "gtest/gtest.h"

TEST(weights_check, initialization_test_1d)
{
    //given
    int number_of_elements = 100;

    //when
    Weights weights(number_of_elements);

    //then
    ASSERT_EQ(weights.size(), number_of_elements);
}

TEST(weights_check, initialization_test_1d_error)
{
    //given
    int number_of_elements = -100;

    //when
    //then
    ASSERT_ANY_THROW(
            Weights weights(number_of_elements);
    );
}

TEST(weights_check, initialization_test_2d)
{
    //given
    int number_of_elements_X = 20;
    int number_of_elements_Y = 20;

    //when
    Weights weights(number_of_elements_X * number_of_elements_Y);

    //then
    ASSERT_EQ(weights.size(), number_of_elements_X * number_of_elements_Y);
}

TEST(weights_check, initialization_test_2d_error)
{
    //given
    int number_of_elements_X = -20;
    int number_of_elements_Y = 20;

    //when
    //then
    ASSERT_ANY_THROW(
            Weights weights(number_of_elements_X * number_of_elements_Y);
            );
}

TEST(weights_check, values_randomness_test)
{
    //given
    int number_of_elements = 100;
    Weights weights(number_of_elements);

    //when
    //then
    double a, b, c;
    ASSERT_NO_THROW(
for(int i = 2; i < weights.size(); i++)
         {
             a = (double)weights.getWeight(i);
             b = (double)weights.getWeight(i-1);
             c = (double)weights.getWeight(i-2);
             // if three values in a row are the same => randomness error
             if(abs(a - b) < 0.001 && abs(b - c) < 0.001 && abs(a - c) < 0.001)
                 throw std::exception();
         }
    ) << "Values "<< a <<", " << b << ", " << c << " are too close to each other - randomness error" ;
}

TEST(weights_check, out_of_bounds_test_over)
{
    //given
    int number_of_elements = 100;
    Weights weights(number_of_elements);

    //when
    //then
    ASSERT_ANY_THROW(
            auto& temp = weights.getWeight(101);
            );
}

TEST(weights_check, out_of_bounds_test_under)
{
    //given
    int number_of_elements = 100;
    Weights weights(number_of_elements);

    //when
    //then
    ASSERT_ANY_THROW(
            auto& temp = weights.getWeight(-1);
            );
}