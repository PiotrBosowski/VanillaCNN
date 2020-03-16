#pragma once
#include "NeuronFactory.h"
#include "WeightedNeuron.h"

class WeightedNeuronFactory : public NeuronFactory
{
	std::unique_ptr<Neuron> createNeuron() override;
};

