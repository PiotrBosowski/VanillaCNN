//
// Created by piotr on 20/04/11.
//


#include "../Containers/Container.h"
#include "NeuronsConnecting1toAll.h"

void NeuronsConnecting1toAll::connect(Container& sourceContainer, Container& previousContainer)
{
    for (int i = 0; i < sourceContainer.getNumberOfNeurons(); i++) //TODO: iterator / for all neurons in container
    {
        Neuron& sourceNeuron = sourceContainer.getNeuron(i);
        for (int j = 0; j < previousContainer.getNumberOfNeurons(); j++)
        {
            Neuron& previousNeuron = previousContainer.getNeuron(j);
            sourceNeuron.connect(previousNeuron);
        }
    }
}
