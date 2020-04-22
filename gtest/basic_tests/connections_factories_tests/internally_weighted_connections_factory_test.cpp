//
// Created by piotr on 20/04/22.
//

#include <Containers/Container.h>
#include <Containers/Vectors/WeightlessVector.h>
#include <Containers/Matrices/InternallyWeightedMatrix.h>
#include <ConnectionsFactories/InternallyWeightedConnectionsFactory.h>
#include "gtest/gtest.h"

TEST(internally_weighted_connections_factory_test, make_connections_test)
{
    //given
    int neuronIndex = 5;
    int numberOfConnections = 15;
    int numberOfSourceNeurons = 10;
    Neuron one;
    WeightlessVector sourceContainer(numberOfSourceNeurons);
    InternallyWeightedConnectionsFactory connFact;
    std::vector<Neuron*>connections(numberOfConnections, &one);

    //when
    connFact.makeConnections(neuronIndex, sourceContainer, connections);

    //then
    for (int i = 0; i < numberOfSourceNeurons; ++i) {
        if(i == neuronIndex)
            ASSERT_EQ(sourceContainer.getNeuron(i).getNumberOfConnections(), numberOfConnections);
        else
            ASSERT_EQ(sourceContainer.getNeuron(i).getNumberOfConnections(), 0);
    }
}

TEST(internally_weighted_connections_factory_test, bad_source_container_type_test)
{
    //given
    InternallyWeightedConnectionsFactory connFact;
    auto bad_matrix = InternallyWeightedMatrix(5, 5, 5, 5);
    //when
    ASSERT_ANY_THROW(connFact.makeConnections(0, bad_matrix, std::vector<Neuron*>()););
}