#pragma once
#include "Neuron.h"
class WeightlessNeuron : public Neuron
{
public:
	void calculateValue() override;
};

