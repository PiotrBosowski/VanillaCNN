//
// Created by piotr on 20/04/22.
//

#include <ContainersFactories/MatricesFactories/WeightlessMatricesFactory.h>
#include "Docker/Docker.h"
#include "Containers/Matrices/WeightlessMatrix.h"
#include "gtest/gtest.h"

TEST(docker_check, initialization_validation)
{
    //given
    int numberOfContainers = 16;
    int matrixH = 12;
    int matrixW = 17;
    int numberOfNeurons = matrixH * matrixW;
    Docker docker(numberOfContainers);
    auto fact = std::make_unique<WeightlessMatricesFactory>(matrixH, matrixW);
    docker.createContainers(*std::move(fact));

    auto& containers = docker.getContainers();

    for(auto& container : containers){
        ASSERT_NO_THROW(dynamic_cast<WeightlessMatrix&>(*container));
        auto& cont = dynamic_cast<WeightlessMatrix&>(*container);
        ASSERT_EQ(cont.getMatrixWidth(), matrixW);
        ASSERT_EQ(cont.getMatrixHeight(), matrixH);
    }
}