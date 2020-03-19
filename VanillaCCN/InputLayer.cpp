#include "InputLayer.h"
#include <iostream>
#include "Exceptions.h"
#include "WeightlessNeuronFactory.h"

InputLayer::InputLayer(int inputHeight, int inputWidth)
	: Layer2D( /* number of input matrices = */ 1, inputHeight, inputWidth)
{
	neuronFactory = std::make_unique<WeightlessNeuronFactory>();
}

void InputLayer::createContainers()
{
	for(int i = 0; i < numberOfContainers; i++)
		containers.push_back(std::make_unique<Matrix>(*neuronFactory, *neuronsConnectingStrategy, matrixHeight, matrixWidth));
}

std::string InputLayer::getSummary()
{
	std::string result = Layer2D::getSummary() + "\t\tInputLayer\n";
	return result;
}

void InputLayer::connectToPreceeding()
{
}
