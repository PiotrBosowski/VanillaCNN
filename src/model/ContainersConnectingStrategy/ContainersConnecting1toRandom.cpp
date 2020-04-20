//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toRandom.h"
#include "../Layers/Layer.h"

std::vector<std::tuple<Container *, Container *>>
ContainersConnecting1toRandom::proposeConnections(Docker &source, Docker *preceding) {
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    //TODO 1 to random
    return std::vector<std::tuple<Container *, Container *>>();
}
