#include "OutputLayer.h"
#include <iostream>
#include "Exceptions.h"
#include "FullyConnectedLayer.h"
#include "FullyConnectedLayerConnector.h"
#include "ContainersConnecting1toAll.h"
#include "NeuronsConnecting1toAll.h"


OutputLayer::OutputLayer(int numberOfNeurons)
	: Layer1D{ numberOfNeurons }
{
	neuronsConnectingStrategy = std::make_unique<NeuronsConnecting1toAll>();
	containersConnectingStrategy = std::make_unique<ContainersConnecting1toAll>();
}

std::string OutputLayer::getSummary()
{
	std::string result = Layer1D::getSummary() + "\t\tOutputLayer\n";
	return result;
}