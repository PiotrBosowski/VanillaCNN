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



public:
	Neuron(); //if neuron is used as regular neuron
	Neuron(Weights& weights); //if neuron is used as convolutional, it needs to be delivered weights matrix (pattern recognizer)
private:
	const Weights& weights;
	Connections connections;
	double value;
public:
	double getValue();
	void acceptConnection(Neuron& preceding);
	void calculateValue();
};
