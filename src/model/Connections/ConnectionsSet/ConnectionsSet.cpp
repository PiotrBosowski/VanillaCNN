//
// Created by piotr on 20/04/11.
//

#include "ConnectionsSet.h"
#include "../../Neurons/Neuron.h"
#include "../Connection.h"

void ConnectionsSet::add(std::unique_ptr<Connection> newConnection)
{
    connections.push_back(std::move(newConnection));
}

int ConnectionsSet::getNumberOfConnections()
{
    return (int)connections.size();
}

const Neuron & ConnectionsSet::get(int index)
{
    return connections[index]->getNeuron();
}

double ConnectionsSet::getNeuronsValue(int index)
{
    return connections[index]->getNeuron().getValue();
}
