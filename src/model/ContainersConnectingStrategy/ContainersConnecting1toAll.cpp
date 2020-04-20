//
// Created by piotr on 20/04/11.
//

#include "ContainersConnecting1toAll.h"
#include "Layers/Layer.h"

std::vector<std::tuple<Container *, Container *>> ContainersConnecting1toAll::proposeConnections(Docker &source, Docker *preceding) {
    auto result = std::vector<std::tuple<Container*, Container*>>();
    auto& sourceContainers = source.getContainers();
    auto& previousContainers = preceding->getContainers();
    for (auto& sourceContainer : sourceContainers)
    {
        for (auto& previousContainer : previousContainers)
        {
            result.emplace_back(sourceContainer.get(), previousContainer.get());
        }
    }
    return result;
}
