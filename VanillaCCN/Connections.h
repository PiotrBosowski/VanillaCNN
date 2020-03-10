#pragma once
#include <vector>
#include <functional>
#include "Neuron.h"

class Connections
{
private:
	std::vector<std::reference_wrapper<Neuron>> connections;
public:
	void add(Neuron & newConnection);
	int size();
	Neuron& get(int index);
	double getValue(int index);
};