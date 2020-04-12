//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSNEURONSFACTORY_H
#define VANILLACNN_CLION_WEIGHTLESSNEURONSFACTORY_H


#include "NeuronsFactory.h"

class WeightlessNeuronsFactory : public NeuronsFactory
{
    std::unique_ptr<Neuron> createNeuron() override;
};



#endif //VANILLACNN_CLION_WEIGHTLESSNEURONSFACTORY_H
