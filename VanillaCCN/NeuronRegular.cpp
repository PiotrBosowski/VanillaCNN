#include "NeuronRegular.h"
#include <tuple>

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
