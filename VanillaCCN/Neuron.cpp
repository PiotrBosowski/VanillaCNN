#include "Neuron.h"
#include <vector>
#include <functional>

Neuron::Neuron()
	: weights{ std::ref(Weights{}) }
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
	connections.addConnection(preceding);
}

void Neuron::calculateValue()
{
	value = 0;
	for (unsigned int i = 0; i < connections.size(); i++)
	{
		value += connections.get(i).getValue() * weights.get().get(i);
	}
}

void NeuronRegular::acceptConnection(Neuron& preceding)
{
	weightedConnections.push_back(std::tuple<std::reference_wrapper<Neuron>, double>(preceding, rand() / RAND_MAX));
}

void NeuronRegular::calculateValue()
{
	value = 0;
	for (std::tuple<std::reference_wrapper<Neuron>, double>& weightedConnection : weightedConnections)
	{
		value += std::get<0>(weightedConnection).get().getValue() * std::get<1>(weightedConnection);
	}
	//apply activation function...
}
