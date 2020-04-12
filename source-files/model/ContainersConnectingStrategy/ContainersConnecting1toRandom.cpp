//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toRandom.h"
#include "../Layers/Layer.h"

ContainersConnecting1toRandom::ContainersConnecting1toRandom()
{
}

void ContainersConnecting1toRandom::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding)
{
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    //TODO 1 to random
}
