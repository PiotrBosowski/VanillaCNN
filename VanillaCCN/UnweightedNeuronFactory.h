#pragma once
#include "NeuronFactory.h"
#include "UnweightedNeuron.h"
#include "Weights.h"

class UnweightedNeuronFactory : public NeuronFactory
{
public:
	UnweightedNeuronFactory(Weights& weights);
	std::unique_ptr<Neuron> createNeuron() override;

private:
	Weights& weights;
};

