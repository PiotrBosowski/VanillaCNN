//
// Created by piotr on 20/04/11.
//

#include "Docker.h"
#include "Layers/Layer.h"
#include "ContainersFactories/ContainersFactory.h"

Docker::Docker(int numberOfContainers)
        : numberOfContainers(numberOfContainers)
{
}

int Docker::size()
{
    return containers.size();
}

std::vector<std::unique_ptr<Container>>& Docker::getContainers()
{
    return containers;
}

void Docker::createContainers(ContainersFactory& containersFactory)
{
    for (int i = 0; i < numberOfContainers; i++)
    {
        containers.push_back(containersFactory.createContainer());
    }
}

void Docker::createConnections(Docker& previousDocker, ContainersConnectingStrategy& containersConnectingStrategy, NeuronsConnectingStrategy& neuronsConnectingStrategy, ConnectionsFactory& connectionsFactory)
{
    auto connections = containersConnectingStrategy.proposeConnections(*this, previousDocker);
    for(auto& conn : connections)
    {
        std::get<0>(conn)->connect(neuronsConnectingStrategy, connectionsFactory, *std::get<1>(conn));
    }
}

std::ostream &operator<<(std::ostream &os, const Docker &docker) {
    os << "numberOfContainers: " << docker.numberOfContainers << " containers: " << docker.containers.size();
    return os;
}
