//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSFACTORY_H
#define VANILLACNN_CLION_NEURONSFACTORY_H


#include "../Neurons/Neuron.h"
#include <memory>

class NeuronsFactory
{
public:
    virtual std::unique_ptr<Neuron> createNeuron() = 0;
};




#endif //VANILLACNN_CLION_NEURONSFACTORY_H
