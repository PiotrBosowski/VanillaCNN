#pragma once
#include "Neuron.h"
class WeightedNeuron : public Neuron
{
private:
	Weights weights;

public:
	void calculateValue() override;
	void connect(Neuron& preceeding) override;
};

