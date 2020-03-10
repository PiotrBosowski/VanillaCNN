#pragma once
#include <vector>
#include <random>
#include <functional>
#include "Weights.h"
#include "Connections.h"
#include <optional>

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
	void acceptConnection(Neuron& preceding);
	virtual void calculateValue() = 0;
};