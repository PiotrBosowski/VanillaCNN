#pragma once
#include <vector>
#include "Connection.h"

class Neuron
{
private:
	double value;
	std::vector<std::shared_ptr<Connection>> incommingConnections;

public:
	void acceptConnection(std::shared_ptr<Connection>);
	//seems like outputs not needed
	//activation function
};

