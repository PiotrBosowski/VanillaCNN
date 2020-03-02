#pragma once
#include <vector>
#include <random>

/*
Base class for all neuron types.
Contains neuron's value.
*/
class Neuron
{
protected:
	double value;
public:
	double getValue();
	virtual void acceptConnection(Neuron& preceding) = 0;
	virtual void calculateValue() = 0;
};
