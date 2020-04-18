//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_DOCKER_H
#define VANILLACNN_CLION_DOCKER_H


#include <vector>
#include <memory>
#include <ostream>
#include "../Containers/Container.h"

class ContainersConnectingStrategy;
class ContainersFactory;
class NeuronsConnectingStrategy;

class Docker
{

public:
    explicit Docker(int numberOfContainers);

    std::vector<std::unique_ptr<Container>>& getContainers();
    void createContainers(ContainersFactory&);

    friend std::ostream &operator<<(std::ostream &os, const Docker &docker);

    void createConnections(Docker* previousDocker, ContainersConnectingStrategy&, NeuronsConnectingStrategy&, ConnectionsFactory&);
    int size();

private:
    int numberOfContainers;
    std::vector<std::unique_ptr<Container>> containers;
};



#endif //VANILLACNN_CLION_DOCKER_H
