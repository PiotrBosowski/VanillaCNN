//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H
#define VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H

#include <vector>

class Neuron;
class Container;

class NeuronsConnectingStrategy
{
public:
    virtual std::vector<Neuron*> proposeConnections(Neuron& source, Container* preceding) = 0;
};



#endif //VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H
