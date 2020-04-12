//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURONSFACTORY_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURONSFACTORY_H


#include "NeuronsFactory.h"

class ExternallyWeightedNeuronsFactory : public NeuronsFactory
{
    std::unique_ptr<Neuron> createNeuron() override;
};




#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURONSFACTORY_H
