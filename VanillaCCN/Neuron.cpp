#include "Neuron.h"
#include <vector>
#include <functional>

Neuron::Neuron()
	: weights{ Weights{} }
{
}

Neuron::Neuron(Weights& weights)
	: weights{ weights }
{
}

double Neuron::getValue()
{
	return value;
}

void Neuron::acceptConnection(Neuron & preceding)
{
	connections.add(preceding);
}

void Neuron::calculateValue()
{
	value = 0;
	for (unsigned int i = 0; i < connections.size(); i++)
	{
		value += connections.getValue(i) * weights.get(i);
	}
}
