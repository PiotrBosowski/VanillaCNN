//
// Created by piotr on 20/04/11.
//


#include "../Neurons/Neuron.h"
#include "WeightlessNeuronsFactory.h"
#include "../Neurons/WeightlessNeuron.h"

std::unique_ptr<Neuron> WeightlessNeuronsFactory::createNeuron()
{
    return std::make_unique<WeightlessNeuron>();
}
