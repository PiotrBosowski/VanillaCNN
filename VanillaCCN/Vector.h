#pragma once
#include "Container.h"
#include "NeuronsConnectingStrategy.h"
#include <vector>
#include <memory>
#include "Neuron.h"

class Vector : public Container
{
public: 
	Vector(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int vectorHeight);

private:
	int vectorHeight;
	std::vector<std::unique_ptr<Neuron>> row;

public:
	int getVectorHeight();
	Neuron& getNeuron(unsigned int index) override;
	//void populateContainer(const Neuron& source, int width, int height = 1) override;
	unsigned int getNumberOfNeurons() override;
};		

