//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1to1.h"
#include "../exceptions/Exceptions.h"
#include "../Layers/Layer.h"

ContainersConnecting1to1::ContainersConnecting1to1()
{
}

void ContainersConnecting1to1::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding)
{
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    int sourceContainersSize = sourceContainers.size();
    int previousContainersSize = previousContainers.size();
    if (sourceContainers.size() != previousContainers.size())
        throw ConnectingException{"1 to 1 containers connecting strategy requires preceeding and following layers to have the same number of containers"};
    for (int i = 0; i < sourceContainers.size(); i++)
    {
        sourceContainers[i]->connect(neuronsConnectingStrategy, *previousContainers[i]);
    }
}
