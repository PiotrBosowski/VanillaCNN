#pragma once
#include "Neuron.h"
#include "NeuronFactory.h"
#include <memory>

class WeightedNeuronFactory : public NeuronFactory
{
	std::unique_ptr<Neuron> createNeuron() override;
};

