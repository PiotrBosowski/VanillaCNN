#pragma once
#include <optional>
#include "Layer.h"
#include "matrix.h"

class Layer1D : public Layer
{
public:
	Layer1D(int numberOfNeurons);

protected:
	int numberOfNeurons;
	std::vector<std::unique_ptr<Neuron>> neurons;
public:
	int getNumberOfNeurons();
	std::vector<std::unique_ptr<Neuron>>& getNeurons();

	void populateNeurons(std::unique_ptr<Layer>& previousLayer) override;
	void print();
};