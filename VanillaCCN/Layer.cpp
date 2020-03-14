#include "Layer.h"
#include <iostream>

Layer::Layer(int numberOfContainers)
	: numberOfContainers{numberOfContainers}
{
}

void Layer::setPreviousLayer(std::shared_ptr<Layer> previousLayer)
{
	this->previousLayer = previousLayer;
}

std::vector<std::unique_ptr<Container>>& Layer::getContainers()
{
	return containers;
}

int Layer::getNumberOfContainers()
{
	return containers.size();
}

void Layer::connectToPreceeding()
{
	containersConnectingStrategy->connect(*previousLayer);
}

std::string Layer::getSummary()
{
	return "Layer:\n";
}