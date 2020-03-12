#pragma once
#include <vector>
#include <memory>
#include "Neuron.h"
#include "Container.h"

class Matrix : public Container
{
public:
	Matrix(int matrixHeight, int matrixWidth);

private:
	int matrixHeight;
	int matrixWidth;
	std::vector<std::unique_ptr<Neuron>> table; //TODO: simplify implementation of neurons matrix

public:
	int getMatrixHeight();
	int getMatrixWidth();
	Neuron& getNeuron(unsigned int row, unsigned int column);
	void addNeuron(std::unique_ptr<Neuron> newNeuron) override;
	void connect(Container& preceeding) override;
};