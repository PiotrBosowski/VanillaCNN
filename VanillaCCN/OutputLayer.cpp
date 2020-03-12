#include "OutputLayer.h"
#include <iostream>
#include "Exceptions.h"

OutputLayer::OutputLayer(int numberOfNeurons) : Layer1D(numberOfNeurons)
{
}

std::string OutputLayer::getSummary()
{
	std::string result = Layer1D::getSummary() + "\t\tOutputLayer\n";
	return result;
}

void OutputLayer::populateNeurons()
{
	throw PopulatingException{ "bad outputlayer init: it cannot be first layer" };
}

void OutputLayer::connect(Layer& previousLayer)
{
	OutputLayerConnector(*this).connect(previousLayer);
}