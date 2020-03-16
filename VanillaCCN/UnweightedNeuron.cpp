#include "UnweightedNeuron.h"

UnweightedNeuron::UnweightedNeuron(Weights& weights)
	: weights{weights}
{
}

void UnweightedNeuron::calculateValue()
{
	value = 0;
	for (int i = 0; i < connections.getNumberOfConnections(); i++)
	{
		value += connections.getNeuronsValue(i) * weights.getWeight(i);
	}
}
