//
// Created by piotr on 20/04/22.
//

//
// Created by piotr on 20/04/22.
//

#include "Containers/Vectors/WeightlessVector.h"
#include "gtest/gtest.h"

TEST(weightless_vector_check, initialization_validation)
{
    int len = 10;
    WeightlessVector vector(len);
    ASSERT_EQ(vector.getNumberOfNeurons(), len);
    ASSERT_ANY_THROW(WeightlessVector vector(-len););
}