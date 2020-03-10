#include "Connections.h"

void Connections::add(Neuron & newConnection)
{
	connections.push_back(newConnection);
}

int Connections::size()
{
	return connections.size();
}

Neuron & Connections::get(int index)
{
	return connections[index];
}
