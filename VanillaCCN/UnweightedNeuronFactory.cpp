#include "UnweightedNeuronFactory.h"
#include "UnweightedNeuron.h"

std::unique_ptr<Neuron> UnweightedNeuronFactory::createNeuron()
{
	return std::unique_ptr<UnweightedNeuron>();
}
