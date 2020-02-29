#include "Neuron.h"

void Neuron::acceptConnection(Connection * connection)
{
	inputs.push_back(connection);
}

Neuron::~Neuron()
{
}
