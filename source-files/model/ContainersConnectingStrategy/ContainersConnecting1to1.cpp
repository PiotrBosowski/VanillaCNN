//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1to1.h"
#include "../exceptions/Exceptions.h"
#include "../Layers/Layer.h"

ContainersConnecting1to1::ContainersConnecting1to1()
{
}

void ContainersConnecting1to1::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer)
{
    auto& sourceContainers = sourceLayer.getContainers();
    auto& previousContainers = previousLayer.getContainers();
    if (sourceContainers.size() != previousContainers.size())
        throw ConnectingException{"1 to 1 containers connecting strategy requires preceeding and following layers to have the same number of containers"};
    for (int i = 0; i < sourceContainers.size(); i++)
    {
        sourceContainers[i]->connect(neuronsConnectingStrategy, *previousContainers[i]);
    }
}
