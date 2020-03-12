#include "Layer1D.h"
#include <iostream>
#include <memory>
#include "WeightedNeuron.h"
#include <string>
#include "Exceptions.h"

Layer1D::Layer1D(int numberOfNeurons)
	: numberOfNeurons{ numberOfNeurons }, neurons{ Vector{numberOfNeurons} }
{
	if (numberOfNeurons < 1) throw LayerCreatingException("ERROR: incorrect 1D layer dimensions");
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

std::string Layer1D::getSummary()
{
	std::string result = Layer::getSummary() + "\tLayer1D: numberOfNeurons(" + std::to_string(numberOfNeurons) + ")\n";
	return result;
}