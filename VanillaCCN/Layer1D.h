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

	void populateNeurons(Layer& previousLayer) override;
	void populateNeurons() override = 0;
	void connect(Layer& previousLayer) override = 0;
	void print();
};