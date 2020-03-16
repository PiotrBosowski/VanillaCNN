#include "UnweightedNeuronFactory.h"
#include "UnweightedNeuron.h"

UnweightedNeuronFactory::UnweightedNeuronFactory(Weights& weights)
	: weights{ weights }
{
}

std::unique_ptr<Neuron> UnweightedNeuronFactory::createNeuron()
{
	return std::make_unique<UnweightedNeuron>(weights);
}
