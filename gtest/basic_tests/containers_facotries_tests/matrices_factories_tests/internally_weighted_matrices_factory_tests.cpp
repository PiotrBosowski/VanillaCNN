//
// Created by piotr on 20/04/23.
//

#include "ContainersFactories/MatricesFactories/InternallyWeightedMatricesFactory.h"
#include "gtest/gtest.h"

TEST(internally_weighted_matrices_facory_check, init_values_test_pos)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;
    int weightsHeight = 7;
    int weightsWidth = 9;

    //when then
    ASSERT_NO_THROW(InternallyWeightedMatricesFactory factory(matrixHeight, matrixWidth, weightsHeight, weightsWidth););
}

TEST(internally_weighted_matrices_facory_check, init_values_test_neg)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;
    int weightsHeight = 7;
    int weightsWidth = 9;

    //when then
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(-matrixHeight, matrixWidth, weightsHeight, weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(matrixHeight, -matrixWidth, weightsHeight, weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(matrixHeight, matrixWidth, -weightsHeight, weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(matrixHeight, matrixWidth, weightsHeight, -weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(matrixHeight, matrixWidth, -weightsHeight, -weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(-matrixHeight, -matrixWidth, weightsHeight, weightsWidth););
    ASSERT_ANY_THROW(InternallyWeightedMatricesFactory factory(-matrixHeight, -matrixWidth, -weightsHeight, -weightsWidth););
}

#include "Containers/Matrices/InternallyWeightedMatrix.h"

TEST(internally_weighted_matrices_facory_check, createContainer_pos)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;
    int weightsHeight = 7;
    int weightsWidth = 9;

    //when
    InternallyWeightedMatricesFactory factory(matrixHeight, matrixWidth, weightsHeight, weightsWidth);
    auto container = factory.createContainer();
    ASSERT_NO_THROW(dynamic_cast<InternallyWeightedMatrix&>(*container));
    auto& intweimat = dynamic_cast<InternallyWeightedMatrix&>(*container);
    ASSERT_EQ(intweimat.getWeightsHeight(), weightsHeight);
    ASSERT_EQ(intweimat.getWeightsWidth(), weightsWidth);
    ASSERT_EQ(intweimat.getMatrixHeight(), matrixHeight);
    ASSERT_EQ(intweimat.getMatrixWidth(), matrixWidth);
    ASSERT_NO_THROW(
    for (int i = 2; i < weightsHeight * weightsWidth; ++i) {
        auto a = (double)intweimat.getWeight(i);
        auto b = (double)intweimat.getWeight(i-1);
        auto c = (double)intweimat.getWeight(i-2);
        if(abs(a-b) < 0.001 && abs(a-c) < 0.001 && abs(b-c) < 0.001) throw std::exception();
    });
}

