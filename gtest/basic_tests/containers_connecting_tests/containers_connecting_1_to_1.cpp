//
// Created by piotr on 20/04/23.
//

#include <vector>
#include <Docker/Docker.h>
#include <ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h>
#include "ContainersConnectingStrategy/ContainersConnecting1to1.h"
#include "gtest/gtest.h"

TEST(containers_connecting_1_to_1_check, proposeConnections_test_pos)
{
    //given
    int numberOfContainers = 20;
    WeightlessVectorsFactory factory(10);
    Docker first(numberOfContainers);
    first.createContainers(factory);
    Docker second(numberOfContainers);
    second.createContainers(factory);
    ContainersConnecting1to1 connecting;

    //when
    auto connections = connecting.proposeConnections(first, &second);

    //then
    ASSERT_EQ(connections.size(), numberOfContainers);
    auto& firstContainers = first.getContainers();
    auto& secondContainers = second.getContainers();
    for (int i = 0; i < numberOfContainers; ++i)
    {
        ASSERT_EQ(firstContainers[i].get(), std::get<0>(connections[i]));
        ASSERT_EQ(secondContainers[i].get(), std::get<1>(connections[i]));
    }
}

TEST(containers_connecting_1_to_1_check, proposeConnections_test_neg)
{
    //given
    int numberOfContainers = 20;
    WeightlessVectorsFactory factory(10);
    Docker first(numberOfContainers);
    first.createContainers(factory);
    Docker first_unpopulated(numberOfContainers);
    Docker second(numberOfContainers + 1);
    second.createContainers(factory);
    Docker second_unpopulated(numberOfContainers);
    ContainersConnecting1to1 connecting;

    //when then
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first, &second););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first_unpopulated, &second_unpopulated););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first, &second_unpopulated););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first_unpopulated, &second););
}

