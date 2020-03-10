#include "WeightedNeuron.h"

WeightedNeuron::WeightedNeuron()
{
}

void WeightedNeuron::calculateValue()
{
	value = 0;
	for (int i = 0; i < connections.size(); i++)
	{
		value += connections.getValue(i) * weights.get(i);
	}
}
