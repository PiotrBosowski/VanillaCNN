//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toAll.h"
#include "../Layers/Layer.h"

ContainersConnecting1toAll::ContainersConnecting1toAll()
{
}

void ContainersConnecting1toAll::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer)
{
    auto& sourceContainers = sourceLayer.getContainers();
    auto& previousContainers = previousLayer.getContainers();
    for (auto& sourceContainer : sourceContainers)
    {
        for (auto& previousContainer : previousContainers)
        {
            sourceContainer->connect(neuronsConnectingStrategy, *previousContainer);
        }
    }
}
