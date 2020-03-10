#include "UnweightedNeuron.h"

UnweightedNeuron::UnweightedNeuron(Weights& weights)
	: weights{weights}
{
}

void UnweightedNeuron::calculateValue()
{
	value = 0;
	for (int i = 0; i < connections.size(); i++)
	{
		value += connections.getValue(i) * weights.get(i);
	}
}
