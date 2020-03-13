#include "Layer1D.h"
#include <iostream>
#include <memory>
#include "WeightedNeuron.h"
#include <string>
#include "Exceptions.h"

Layer1D::Layer1D(int vectorLength)
	: Layer{ /*numberOfContainers = */ 1  }, vectorLength{ vectorLength }
{
	if (vectorLength < 1) throw LayerCreatingException("ERROR: incorrect 1D layer dimensions");
}

void Layer1D::createContainers()
{
	for (int i = 0; i < numberOfContainers; i++)
		containers.push_back(std::make_unique<Vector>(vectorLength));
}

std::string Layer1D::getSummary()
{
	std::string result = Layer::getSummary() + "\tLayer1D: numberOfNeurons(" + std::to_string(vectorLength) + ")\n";
	return result;
}