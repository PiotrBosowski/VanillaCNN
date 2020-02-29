#pragma once
#include <vector>
#include "Connection.h"

class Neuron
{
private:
	double value;
	std::vector<std::shared_ptr<Connection>> inputs;

public:
	void acceptConnection(Connection * connection);
	//seems like outputs not needed
	//activation function
	~Neuron();
};

