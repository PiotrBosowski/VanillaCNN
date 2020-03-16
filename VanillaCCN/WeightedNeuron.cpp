#include "WeightedNeuron.h"

void WeightedNeuron::calculateValue()
{
	value = 0.0;
	for (int i = 0; i < connections.getNumberOfConnections(); i++)
	{
		value += connections.getNeuronsValue(i) * weights.getWeight(i);
	}
}

void WeightedNeuron::connect(Neuron& preceeding)
{
	connections.add(preceeding);
	weights.add();
}
