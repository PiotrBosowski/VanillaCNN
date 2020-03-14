#include "WeightedNeuronFactory.h"
#include "WeightedNeuron.h"

std::unique_ptr<Neuron> WeightedNeuronFactory::createNeuron()
{
	return std::make_unique<WeightedNeuron>();
}
