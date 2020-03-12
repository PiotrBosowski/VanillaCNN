#include "InputLayer.h"
#include <iostream>
#include "Exceptions.h"

InputLayer::InputLayer(int inputHeight, int inputWidth) : Layer2D(1, inputHeight, inputWidth)
{
}

void InputLayer::populateNeurons(Layer & previousLayer)
{
	throw PopulatingException{ "incorrect initialization of input layer - it should have got no previous layers" };
}

void InputLayer::populateNeurons()
{
	matrices.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
}

std::string InputLayer::getSummary()
{
	std::string result = Layer2D::getSummary() + "\t\tInputLayer\n";
	return result;
}

void InputLayer::connect(Layer& previousLayer)
{
	throw ConnectingException{"cannot connect anything to input layer"};
}

InputLayer::~InputLayer()
{
}
