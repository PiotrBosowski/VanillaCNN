#include "WeightedNeuron.h"
void WeightedNeuron::calculateValue()
{
	value = 0;
	for (int i = 0; i < connections.size(); i++)
	{
		value += connections.getValue(i) * weights.get(i);
	}
}

void WeightedNeuron::connect(Neuron& preceeding)
{
	connections.add(preceeding);
	weights.add();
}
