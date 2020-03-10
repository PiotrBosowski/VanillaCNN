#include "Connections.h"
#include "Neuron.h"

void Connections::add(Neuron & newConnection)
{
	connections.push_back(newConnection);
}

int Connections::size()
{
	return (int)connections.size();
}

const Neuron & Connections::get(int index)
{
	return connections[index];
}

double Connections::getValue(int index)
{
	return connections[index].get().getValue();
}
