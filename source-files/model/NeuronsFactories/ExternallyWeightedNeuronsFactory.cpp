//
// Created by piotr on 20/04/11.
//


#include "../Neurons/Neuron.h"
#include "ExternallyWeightedNeuronsFactory.h"
#include "../Neurons/WeightlessNeuron.h"

std::unique_ptr<Neuron> ExternallyWeightedNeuronsFactory::createNeuron()
{
    return std::make_unique<WeightlessNeuron>();
}