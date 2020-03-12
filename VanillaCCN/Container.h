#pragma once
#include <memory>

class Neuron;

class Container
{
public:
	virtual void addNeuron(std::unique_ptr<Neuron> newNeuron) = 0;
	virtual void connect(Container& preceedingContainer) = 0; //connects all to all
};
