#include "Layer1D.h"
#include <iostream>
#include <memory>

Layer1D::Layer1D(int numberOfNeurons)
	: numberOfNeurons{ numberOfNeurons }
{
	if (numberOfNeurons < 1) throw std::exception("ERROR: incorrect 1D layer dimensions");
}

int Layer1D::getNumberOfNeurons()
{
	return numberOfNeurons;
}

std::vector<std::unique_ptr<Neuron>>& Layer1D::getNeurons()
{
	return neurons;
}

void Layer1D::populateNeurons(std::unique_ptr<Layer>&)
{
	for (int i = 0; i < numberOfNeurons; i++)
		neurons.push_back(std::move(std::unique_ptr<Neuron>{new Neuron{}}));
}

void Layer1D::print()
{
	Layer::print();
	std::cout << "  Layer1D: numberOfNeurons(" << numberOfNeurons << ")" << std::endl;
}