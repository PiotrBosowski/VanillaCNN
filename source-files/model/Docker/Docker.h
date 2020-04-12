//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_DOCKER_H
#define VANILLACNN_CLION_DOCKER_H


#include <vector>
#include <memory>
#include "../ContainersFactories/ContainersFactory.h"
#include "../Containers/Container.h"
#include "../ConnectionsFactories/ConnectionsFactory.h"

class ContainersConnectingStrategy;
class ContainersFactory;
class NeuronsFactory;
class NeuronsConnectingStrategy;

class Docker
{

public:
    Docker(int numberOfContainers);

    std::vector<std::unique_ptr<Container>>& getContainers();
    int size();
    void createContainers(ContainersFactory&, NeuronsFactory&);
    void createConnections(Docker* previousDocker, ContainersConnectingStrategy&, NeuronsConnectingStrategy&, ConnectionsFactory&);


private:
    int numberOfContainers;
    std::vector<std::unique_ptr<Container>> containers;
};



#endif //VANILLACNN_CLION_DOCKER_H
