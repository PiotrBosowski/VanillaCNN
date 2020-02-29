#include "Neuron.h"

void Neuron::acceptConnection(std::shared_ptr<Connection> connection)
{
	incommingConnections.push_back(connection);
}