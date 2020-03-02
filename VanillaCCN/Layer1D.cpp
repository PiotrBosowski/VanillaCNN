#include "Layer1D.h"
#include <iostream>
#include <memory>
#include "NeuronRegular.h"

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

void Layer1D::populateNeurons(Layer& _)
{
	for (int i = 0; i < numberOfNeurons; i++)
		neurons.push_back(std::move(std::unique_ptr<Neuron>{new NeuronRegular{}}));
}

void Layer1D::print()
{
	Layer::print();
	std::cout << "  Layer1D: numberOfNeurons(" << numberOfNeurons << ")" << std::endl;
}