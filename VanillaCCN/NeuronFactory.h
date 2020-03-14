#pragma once
#include "Neuron.h"
#include <memory>

class NeuronFactory
{
public:
	virtual std::unique_ptr<Neuron> createNeuron() = 0;
};

