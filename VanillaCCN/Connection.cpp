#include "Connection.h"
#include <stdlib.h>
#include "Neuron.h"
#include <memory>

Connection::Connection(std::unique_ptr<Neuron>& first, std::unique_ptr<Neuron>& second)
	: first{ std::move(first)}, second{std::move(second)}
{
	weight = rand() / (double)RAND_MAX;
	first->acceptConnection(this);
	second->acceptConnection(this);
}
