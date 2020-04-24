//
// Created by piotr on 20/04/23.
//

#include <vector>
#include <Docker/Docker.h>
#include <ContainersFactories/VectorsFactories/WeightlessVectorsFactory.h>
#include "ContainersConnectingStrategy/ContainersConnecting1toAll.h"
#include "gtest/gtest.h"

TEST(containers_connecting_1_to_all_check, proposeConnections_test_pos)
{
    //given
    int numberOfContainers_source = 29;
    int numberOfContainers_previous = 40;
    WeightlessVectorsFactory factory(10);
    Docker source(numberOfContainers_source);
    source.createContainers(factory);
    Docker previous(numberOfContainers_previous);
    previous.createContainers(factory);
    ContainersConnecting1toAll connecting;

    //when
    auto connections = connecting.proposeConnections(source, previous);

    //then
    ASSERT_EQ(connections.size(), numberOfContainers_source*numberOfContainers_previous);
    auto& firstContainers = source.getContainers();
    auto& secondContainers = previous.getContainers();
    for (int i = 0; i < numberOfContainers_source; ++i)
    {
        for (int j = 0; j < numberOfContainers_previous; ++j) {
            ASSERT_EQ(firstContainers[i].get(), std::get<0>(connections[i * numberOfContainers_previous + j]))
            << "missmached values: " << i << " source container doesnt match with " << i * numberOfContainers_previous + j << " proposed container";
            ASSERT_EQ(secondContainers[j].get(), std::get<1>(connections[i * numberOfContainers_previous + j]))
            << "missmached values: " << j << " previous container doesnt match with " << i * numberOfContainers_previous + j << " proposed container";
        }
    }
}

TEST(containers_connecting_1_to_all_check, proposeConnections_test_neg)
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
    ContainersConnecting1toAll connecting;

    //when then
    ASSERT_NO_THROW(auto connections = connecting.proposeConnections(first, second););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first_unpopulated, second_unpopulated););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first, second_unpopulated););
    ASSERT_ANY_THROW(auto connections = connecting.proposeConnections(first_unpopulated, second););
}

