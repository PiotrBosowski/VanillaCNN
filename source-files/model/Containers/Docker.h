//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_DOCKER_H
#define VANILLACNN_CLION_DOCKER_H


#include <vector>
#include <memory>
#include "../ContainersFactories/ContainersFactory.h"
#include "Container.h"
#include "../ContainersConnectingStrategy/ContainersConnectingStrategy.h"

class Docker
{
public:
    Docker(Layer& thisLayer, int numberOfContainers, std::unique_ptr<ContainersFactory> containersFactory,
           std::unique_ptr<ContainersConnectingStrategy> containersConnectingStrategy,
           std::unique_ptr<NeuronsFactory> neuronsFactory,
           std::unique_ptr<NeuronsConnectingStrategy> neuronsConnectingStrategy);

    std::vector<std::unique_ptr<Container>>& getContainers();
    int size();
    void connectToPreceding(Layer* preceding);

private:
    Layer& thisLayer;
    std::vector<std::unique_ptr<Container>> containers;
    std::unique_ptr<ContainersFactory> containersFactory;
    std::unique_ptr<ContainersConnectingStrategy> containersConnectingStrategy;
    std::unique_ptr<NeuronsFactory> neuronsFactory;
    std::unique_ptr<NeuronsConnectingStrategy> neuronsConnectingStrategy;
    void addContainers(int numberOfContainers);
};



#endif //VANILLACNN_CLION_DOCKER_H
