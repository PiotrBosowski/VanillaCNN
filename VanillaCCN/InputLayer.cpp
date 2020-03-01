#include "InputLayer.h"
#include <iostream>

InputLayer::InputLayer(int inputHeight, int inputWidth) : Layer2D(1, inputHeight, inputWidth)
{
}

void InputLayer::print()
{
	Layer2D::print();
	std::cout << "    InputLayer" << std::endl;
}

InputLayer::~InputLayer()
{
}
