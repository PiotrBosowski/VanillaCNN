//
// Created by piotr on 20/04/22.
//

#include <Containers/Container.h>
#include <Containers/Vectors/WeightlessVector.h>
#include <Containers/Matrices/InternallyWeightedMatrix.h>
#include <ConnectionsFactories/ExternallyWeightedConnectionsFactory.h>
#include "gtest/gtest.h"

TEST(externally_weighted_connections_factory_test, make_connections_test)
{
    //given
    int neuronIndex = 8;
    int numberOfConnections = 15;
    Neuron one;
    InternallyWeightedMatrix sourceContainer(5, 5, 5, 5);
    ExternallyWeightedConnectionsFactory connFact;
    std::vector<Neuron*>connections(numberOfConnections, &one);

    //when
    connFact.makeConnections(neuronIndex, sourceContainer, connections);

    //then
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(sourceContainer.getWidthFromIndex(neuronIndex) == j && sourceContainer.getHeightFromIndex(neuronIndex) == i)
                ASSERT_EQ(sourceContainer.getNeuron(i, j).getNumberOfConnections(), numberOfConnections);
            else
                ASSERT_EQ(sourceContainer.getNeuron(i, j).getNumberOfConnections(), 0);
        }
    }
}

TEST(externally_weighted_connections_factory_test, bad_source_container_type_test)
{
    //given
    int neuronIndex = 5;
    int numberOfConnections = 15;
    int numberOfSourceNeurons = 10;
    Neuron one;
    WeightlessVector bad_matrix(numberOfSourceNeurons);
    ExternallyWeightedConnectionsFactory connFact;
    std::vector<Neuron*>connections(numberOfConnections, &one);
    //when
    ASSERT_ANY_THROW(connFact.makeConnections(0, bad_matrix, std::vector<Neuron*>()););
}