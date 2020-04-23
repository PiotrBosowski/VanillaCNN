//
// Created by piotr on 20/04/23.
//

#include "ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h"
#include "gtest/gtest.h"

TEST(weightless_matrices_facory_check, init_values_test_pos)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;

    //when then
    ASSERT_NO_THROW(WeightlessMatricesFactory factory(matrixHeight, matrixWidth););
}

TEST(weightless_matrices_facory_check, init_values_test_neg)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;

    //when then
    ASSERT_ANY_THROW(WeightlessMatricesFactory factory(-matrixHeight, matrixWidth););
    ASSERT_ANY_THROW(WeightlessMatricesFactory factory(matrixHeight, -matrixWidth););
    ASSERT_ANY_THROW(WeightlessMatricesFactory factory(-matrixHeight, -matrixWidth););
}

#include "Containers/Matrices/WeightlessMatrix.h"

TEST(weightless_matrices_facory_check, createContainer_pos)
{
    //given
    int matrixHeight = 29;
    int matrixWidth = 31;

    //when
    WeightlessMatricesFactory factory(matrixHeight, matrixWidth);
    auto container = factory.createContainer();

    //then
    ASSERT_NO_THROW(dynamic_cast<WeightlessMatrix&>(*container));
    auto& weimat = dynamic_cast<WeightlessMatrix&>(*container);
    ASSERT_EQ(weimat.getMatrixHeight(), matrixHeight);
    ASSERT_EQ(weimat.getMatrixWidth(), matrixWidth);
}

