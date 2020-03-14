#pragma once
#include <vector>
#include "Weights.h"
#include "Connections.h"

/*
Base class for all neuron types.
Contains neuron's value.
*/
class Neuron
{
protected:
	Connections connections;
	double value = 0;
public:
	double getValue();
	virtual void connect(Neuron& preceding);
	virtual void calculateValue() = 0;
};