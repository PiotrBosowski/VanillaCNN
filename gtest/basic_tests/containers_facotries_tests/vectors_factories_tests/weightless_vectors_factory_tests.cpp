//
// Created by piotr on 20/04/23.
//

#include <Containers/Vectors/WeightlessVector.h>
#include "ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h"
#include "gtest/gtest.h"

TEST(weightless_vector_facory_check, init_values_test_pos)
{
    //given
    int vectorLen = 31;

    //when then
    ASSERT_NO_THROW(WeightlessVectorsFactory factory(vectorLen););
}

TEST(weightless_vector_facory_check, init_values_test_neg)
{
    //given
    int vectorLen = 29;

    //when then
    ASSERT_ANY_THROW(WeightlessVectorsFactory factory(-vectorLen););
}

TEST(weightless_vector_facory_check, createContainer_pos)
{
    //given
    int vectorLen = 31;

    //when
    WeightlessVectorsFactory factory(vectorLen);
    auto container = factory.createContainer();

    //then
    ASSERT_NO_THROW(dynamic_cast<WeightlessVector&>(*container));
    auto& weimat = dynamic_cast<WeightlessVector&>(*container);
    ASSERT_EQ(weimat.getNumberOfNeurons(), vectorLen);
}

