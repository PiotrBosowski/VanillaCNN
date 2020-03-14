#include "Neuron.h"

double Neuron::getValue()
{
	return value;
}

void Neuron::connect(Neuron & preceding)
{
	connections.add(preceding);
}