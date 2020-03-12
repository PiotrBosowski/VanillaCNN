#pragma once
#include <optional>
#include "Layer.h"
#include "matrix.h"
#include "Vector.h"

class Layer1D : public Layer
{
public:
	Layer1D(int numberOfNeurons);

protected:
	int numberOfNeurons;
	Vector neurons;
public:
	int getNumberOfNeurons();
	Vector& getNeurons();

	void populateNeurons(Layer& previousLayer) override;
	void populateNeurons() override = 0;
	void connect(Layer& previousLayer) override = 0;
	void print();
};