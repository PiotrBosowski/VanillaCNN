#pragma once
#include "Container.h"
#include <vector>
#include <memory>
#include "Neuron.h"

class Vector : public Container
{
public: 
	Vector(int vectorHeight);

private:
	int vectorHeight;
	std::vector<std::unique_ptr<Neuron>> row;

public:
	int getVectorHeight();
	Neuron& getNeuron(unsigned int index);
	void addNeuron(std::unique_ptr<Neuron> newNeuron) override;
	void connect(Container& preceeding) override;
};		

