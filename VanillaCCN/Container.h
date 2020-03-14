#pragma once
#include <memory>
#include "NeuronsConnectingStrategy.h"
#include "NeuronFactory.h"

class Neuron;

class Container
{
public:
	Container(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy);

private:
	NeuronsConnectingStrategy& neuronsConnectingStrategy;
	NeuronFactory& neuronFactory;

public:
	virtual void connect(Container& preceedingContainer);
	virtual Neuron& getNeuron(unsigned int index) = 0;
	virtual unsigned int getNumberOfNeurons() = 0;
};
