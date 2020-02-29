#include "OutputLayer.h"
#include <iostream>

OutputLayer::OutputLayer(int numberOfNeurons) : Layer1D(numberOfNeurons)
{
}

void OutputLayer::print()
{
	Layer1D::print();
	std::cout << "    OutputLayer" << std::endl;
}

OutputLayer::~OutputLayer()
{
}
