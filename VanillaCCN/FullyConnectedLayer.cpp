#include "FullyConnectedLayer.h"
#include "FullyConnectedLayerConnector.h"
#include <iostream>
#include "Exceptions.h"

FullyConnectedLayer::FullyConnectedLayer(int numberOfNeurons) : Layer1D(numberOfNeurons)
{
}

void FullyConnectedLayer::populateNeurons()
{
	throw PopulatingException{ "bad fully connected layer init: it cannot be initialized without any layers before!" };
}

std::string FullyConnectedLayer::getSummary()
{
	std::string result = Layer1D::getSummary() + "\t\tFullyConnectedLayer\n";
	return result;
}

void FullyConnectedLayer::connect(Layer& previousLayer)
{
	FullyConnectedLayerConnector(*this).connect(previousLayer);
}
