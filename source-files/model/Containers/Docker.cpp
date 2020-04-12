//
// Created by piotr on 20/04/11.
//

#include "Docker.h"

void Docker::addContainers(int numberOfContainers)
{
    for (int i = 0; i < numberOfContainers; i++)
    {
        containers.push_back(containersFactory->createContainer(*containersConnectingStrategy, *neuronsFactory, *neuronsConnectingStrategy));
    }
}

int Docker::size()
{
    return containers.size();
}

std::vector<std::unique_ptr<Container>>& Docker::getContainers()
{
    return containers;
}

Docker::Docker(Layer& thisLayer, int numberOfContainers, std::unique_ptr<ContainersFactory> containersFactory,
               std::unique_ptr<ContainersConnectingStrategy> containersConnectingStrategy,
               std::unique_ptr<NeuronsFactory> neuronsFactory,
               std::unique_ptr<NeuronsConnectingStrategy> neuronsConnectingStrategy)
               :
               thisLayer(thisLayer),
               containersFactory{ std::move(containersFactory) },
               containersConnectingStrategy{ std::move(containersConnectingStrategy) },
               neuronsFactory{ std::move(neuronsFactory)},
               neuronsConnectingStrategy{ std::move(neuronsConnectingStrategy) }
{
    addContainers(numberOfContainers);
}

void Docker::connectToPreceding(Layer* preceding) {
    containersConnectingStrategy->connect(*neuronsConnectingStrategy, thisLayer, *preceding);
}
