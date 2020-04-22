//
// Created by piotr on 20/04/22.
//

#include "Containers/Matrices/InternallyWeightedMatrix.h"
#include "gtest/gtest.h"

TEST(internally_weighted_matrix_check, initialization_validation)
{
    int matH = 10;
    int matW = 15;
    int weiH = 33;
    int weiW = 45;
    InternallyWeightedMatrix matrix(matH, matW, weiH, weiW);
    ASSERT_EQ(matrix.getMatrixHeight(), matH);
    ASSERT_EQ(matrix.getMatrixWidth(), matW);
    ASSERT_EQ(matrix.getNumberOfNeurons(), matH*matW);
    ASSERT_EQ(matrix.getWeightsHeight(), weiH);
    ASSERT_EQ(matrix.getWeightsWidth(), weiW);
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(-matH, matW, weiH, weiW););
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(matH, -matW, weiH, weiW););
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(matH, matW, -weiH, weiW););
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(matH, matW, weiH, -weiW););
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(-matH, -matW, weiH, weiW););
    ASSERT_ANY_THROW(InternallyWeightedMatrix matrix(matH, matW, -weiH, -weiW););
}

TEST(internally_weighted_matrix_check, randomness_test)
{
    int matH = 25;
    int matW = 35;
    int weiH = 33;
    int weiW = 45;
    InternallyWeightedMatrix matrix(matH, matW, weiH, weiW);
    ASSERT_NO_THROW(
    for(int i = 2; i < weiH * weiW; i++)
    {
        auto a = (double) matrix.getWeight(i);
        auto b = (double) matrix.getWeight(i - 1);
        auto c = (double) matrix.getWeight(i - 2);
        if (abs(a - b) < 0.001 && abs(b - c) < 0.001 && abs(a - c) < 0.001) throw std::exception();
    });
}