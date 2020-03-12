#include "Layer1D.h"
#include <iostream>
#include <memory>
#include "WeightedNeuron.h"

Layer1D::Layer1D(int numberOfNeurons)
	: numberOfNeurons{ numberOfNeurons }, neurons{ Vector{numberOfNeurons} }
{
	if (numberOfNeurons < 1) throw std::exception("ERROR: incorrect 1D layer dimensions");
}

int Layer1D::getNumberOfNeurons()
{
	return numberOfNeurons;
}

Vector& Layer1D::getNeurons()
{
	return neurons;
}

void Layer1D::populateNeurons(Layer& previousLayer)
{
	for (int i = 0; i < numberOfNeurons; i++)
		neurons.addNeuron(std::make_unique<WeightedNeuron>());
}

void Layer1D::print()
{
	Layer::print();
	std::cout << "  Layer1D: numberOfNeurons(" << numberOfNeurons << ")" << std::endl;
}