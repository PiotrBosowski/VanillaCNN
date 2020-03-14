#pragma once
#include <vector>
#include "Neuron.h"
#include "Container.h"

class Matrix : public Container
{
public:
	Matrix(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStratetgy, int matrixHeight, int matrixWidth);

private:
	int matrixHeight;
	int matrixWidth;
	std::vector<std::unique_ptr<Neuron>> table; //TODO: simplify implementation of neurons matrix

public:
	int getMatrixHeight();
	int getMatrixWidth();
	Neuron& getNeuron(unsigned int index) override;
	Neuron& getNeuron(unsigned int row, unsigned int column);
	unsigned int getNumberOfNeurons() override;
};