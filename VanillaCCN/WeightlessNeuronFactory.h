#pragma once
#include "NeuronFactory.h"
#include "WeightlessNeuron.h"

class WeightlessNeuronFactory : public NeuronFactory
{
	std::unique_ptr<Neuron> createNeuron() override;
};

