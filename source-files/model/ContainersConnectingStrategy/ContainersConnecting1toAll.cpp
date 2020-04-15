//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toAll.h"
#include "../Layers/Layer.h"

ContainersConnecting1toAll::ContainersConnecting1toAll()
{
}

void ContainersConnecting1toAll::proposeConnections(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding)
{
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    for (auto& sourceContainer : sourceContainers)
    {
        for (auto& previousContainer : previousContainers)
        {
            sourceContainer->connect(neuronsConnectingStrategy, *previousContainer);
        }
    }
}
