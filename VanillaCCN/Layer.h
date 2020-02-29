#pragma once
#include "Neuron.h"
#include <memory>

class Layer
{
public:
	virtual void populateNeurons(std::unique_ptr<Layer>& previousLayer) = 0;

	virtual void print();
};
