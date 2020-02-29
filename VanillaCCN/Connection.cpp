#include "Connection.h"
#include <stdlib.h>
#include "Neuron.h"
#include <memory>

Connection::Connection(std::unique_ptr<Neuron>& preceding, std::unique_ptr<Neuron>& following)
	: preceding{ preceding }, following{ following }
{
	weight = rand() / (double)RAND_MAX;
	this->following->acceptConnection(std::shared_ptr<Connection>(this));
}
