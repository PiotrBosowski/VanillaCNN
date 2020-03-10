#include "Neuron.h"
#include <vector>
#include <functional>

double Neuron::getValue()
{
	return value;
}

void Neuron::acceptConnection(Neuron & preceding)
{
	connections.add(preceding);
}