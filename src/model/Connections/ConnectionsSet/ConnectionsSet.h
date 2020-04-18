//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONNECTIONSSET_H
#define VANILLACNN_CLION_CONNECTIONSSET_H

#include <vector>
#include <memory>
#include "../Connection.h"

class Connection;
class Neuron;

class ConnectionsSet
{
private:
    std::vector<std::unique_ptr<Connection>> connections;
public:
    void add(std::unique_ptr<Connection> newConnection);
    int getNumberOfConnections();
    const Neuron& get(int index);
    double getNeuronsValue(int index);
};


#endif //VANILLACNN_CLION_CONNECTIONSSET_H
