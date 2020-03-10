#pragma once
#include "Neuron.h"
class WeightedNeuron :
	public Neuron
{
public:
	WeightedNeuron();
private:
	Weights weights;

public:
	void calculateValue() override;
};

