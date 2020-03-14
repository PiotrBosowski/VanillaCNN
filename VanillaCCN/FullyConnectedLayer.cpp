#include "FullyConnectedLayer.h"
#include <iostream>
#include "ContainersConnecting1toAll.h"
#include "NeuronsConnecting1toAll.h"
#include "Exceptions.h"

FullyConnectedLayer::FullyConnectedLayer(int numberOfNeurons)
	: Layer1D{ numberOfNeurons }
{
	neuronsConnectingStrategy = std::make_unique<NeuronsConnecting1toAll>();
	containersConnectingStrategy = std::make_unique<ContainersConnecting1toAll>(*this);
}

std::string FullyConnectedLayer::getSummary()
{
	std::string result = Layer1D::getSummary() + "\t\tFullyConnectedLayer\n";
	return result;
}
