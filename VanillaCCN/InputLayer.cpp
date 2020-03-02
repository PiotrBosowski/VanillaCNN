#include "InputLayer.h"
#include <iostream>

InputLayer::InputLayer(int inputHeight, int inputWidth) : Layer2D(1, inputHeight, inputWidth)
{
}

void InputLayer::populateNeurons(Layer & previousLayer)
{
	throw std::exception{ "incorrect initialization of input layer - it should have got no previous layers" };
}

void InputLayer::populateNeurons()
{
	matrices.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
}

void InputLayer::print()
{
	Layer2D::print();
	std::cout << "    InputLayer" << std::endl;
}

InputLayer::~InputLayer()
{
}
