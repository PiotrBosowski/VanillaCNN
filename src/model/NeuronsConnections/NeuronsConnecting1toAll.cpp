//
// Created by piotr on 20/04/11.
//


#include "../Containers/Container.h"
#include "NeuronsConnecting1toAll.h"

//TODO REFERENCES instead of POINTERS
std::vector<Neuron *> NeuronsConnecting1toAll::proposeSingleNeuronConnections(Container &source, Container *preceding) {
    std::vector<Neuron*>result;
    for (int j = 0; j < preceding->getNumberOfNeurons(); j++)
    {
        Neuron* previousNeuron = &preceding->getNeuron(j);
        result.emplace_back(previousNeuron);
    }
    moveToTheNextNeuron((int)preceding->getNumberOfNeurons());
    return result;
}