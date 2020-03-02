#pragma once
#include "Neuron.h"
#include <memory>

class Layer
{
public:
	virtual void populateNeurons(Layer& previousLayer) = 0;
	virtual void populateNeurons() = 0;

	virtual void print();
};
