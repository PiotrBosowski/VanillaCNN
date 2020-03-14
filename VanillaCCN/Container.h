#pragma once
#include <memory>
#include "NeuronsConnectingStrategy.h"

class Neuron;

class Container
{
public:
	Container(NeuronsConnectingStrategy& neuronsConnectingStrategy);

private:
	NeuronsConnectingStrategy& neuronsConnectingStratetgy;

public:
	virtual void addNeuron(std::unique_ptr<Neuron> newNeuron) = 0;
	virtual void populateContainer(const Neuron& source, int width, int height = 1) = 0;
	virtual void connect(Container& preceedingContainer) = 0;
};
