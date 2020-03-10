#pragma once
#include "Neuron.h"
class UnweightedNeuron : public Neuron
{
public:
	UnweightedNeuron(Weights& weights);
private:
	Weights& weights;

public:
	void calculateValue() override;
};