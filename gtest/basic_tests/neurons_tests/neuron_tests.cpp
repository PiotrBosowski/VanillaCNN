//
// Created by piotr on 20/04/20.
//

#include <Connections/InternallyWeightedConnection.h>
#include "gtest/gtest.h"
#include "Neurons/Neuron.h"

TEST(neuron_check, initial_values_test)
{
    //given
    Neuron other{};
    Neuron neuron(1.0);
    neuron.acceptConnection(std::make_unique<InternallyWeightedConnection>(other));
    neuron.acceptConnection(std::make_unique<InternallyWeightedConnection>(other));
    neuron.acceptConnection(std::make_unique<InternallyWeightedConnection>(other));
    neuron.acceptConnection(std::make_unique<InternallyWeightedConnection>(other));

    ASSERT_EQ(neuron.getNumberOfConnections(), 4) << "incorrect number of connections";
    ASSERT_NEAR(neuron.getValue(), 1.0, 0.001) << "initial value differs from expected";
}
