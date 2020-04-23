//
// Created by piotr on 20/04/22.
//

#include "Containers/Matrices/WeightlessMatrix.h"
#include "gtest/gtest.h"

TEST(weightless_matrix_check, initialization_validation)
{
    int matH = 10;
    int matW = 15;
    WeightlessMatrix vector(matH, matW);
    ASSERT_EQ(vector.getMatrixHeight(), matH);
    ASSERT_EQ(vector.getMatrixWidth(), matW);
    ASSERT_EQ(vector.getNumberOfNeurons(), matH * matW);
    ASSERT_ANY_THROW(WeightlessMatrix matrix(-matH, matW););
    ASSERT_ANY_THROW(WeightlessMatrix matrix(matH, -matW););
    ASSERT_ANY_THROW(WeightlessMatrix matrix(-matH, -matW););
}
