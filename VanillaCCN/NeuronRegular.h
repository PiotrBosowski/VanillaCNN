#pragma once
#include "Neuron.h"
#include <tuple>

/*
Base class for neurons of Dense - fully connected layers.
Contains vector of tuples of connected neurons and their weights.
*/
class NeuronRegular : public Neuron
{
private:
	std::vector<std::tuple<std::reference_wrapper<Neuron>, double>> weightedConnections;

public:
	void acceptConnection(Neuron& preceding) override;
	virtual void calculateValue() override;
};
