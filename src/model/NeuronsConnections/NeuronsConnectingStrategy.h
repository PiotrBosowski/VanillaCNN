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
    //returns a vector of connections for a single source neuron, to get a full set of connections you need to invoke the function N times (N - number of neurons)
    virtual std::vector<Neuron*> proposeSingleNeuronConnections(Container& source, Container* preceding) = 0;

protected:
    int currentNeuronHeight = 0;
    int currentNeuronWidth = 0;
    void moveToTheNextNeuron(int sourceHeight, int sourceWidth = 1);
};

#endif //VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H
