#pragma once
#include "NeuronFactory.h"

class UnweightedNeuronFactory : public NeuronFactory
{
	std::unique_ptr<Neuron> createNeuron() override;
};

