//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1to1.h"
#include "../exceptions/Exceptions.h"
#include "../Layers/Layer.h"

ContainersConnecting1to1::ContainersConnecting1to1()
{
}

void ContainersConnecting1to1::proposeConnections(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding)
{
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    if (sourceContainers.size() != previousContainers.size())
        throw ConnectingException{"1 to 1 containers connecting strategy requires preceding and following layers to have the same number of containers"};
    for (int i = 0; i < sourceContainers.size(); i++)
    {
        sourceContainers[i]->connect(neuronsConnectingStrategy, *previousContainers[i]);
    }
}

std::vector<std::tuple<Container*, Container*>>
ContainersConnecting1to1::proposeConnections(Docker &source, Docker *preceding) {
    auto result = std::vector<std::tuple<Container*, Container*>>();
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    if (sourceContainers.size() != previousContainers.size())
        throw ConnectingException{"1 to 1 containers connecting strategy requires preceding and following layers to have the same number of containers"};
    for (int i = 0; i < sourceContainers.size(); i++)
    {
        result.emplace_back(sourceContainers[i].get(), previousContainers[i].get());
    }
    return result;
}
