//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toRandom.h"
#include "../Layers/Layer.h"

ContainersConnecting1toRandom::ContainersConnecting1toRandom()
{
}

void ContainersConnecting1toRandom::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer)
{
    auto& sourceContainers = sourceLayer.getContainers();
    auto& previousContainers = previousLayer.getContainers();
    //TODO 1 to random
}
