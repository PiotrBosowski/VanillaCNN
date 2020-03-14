#include "WeightlessNeuronFactory.h"
#include "WeightlessNeuron.h"

std::unique_ptr<Neuron> WeightlessNeuronFactory::createNeuron()
{
	return std::make_unique<WeightlessNeuron>();
}
