#include "FullyConnectedLayer.h"
#include <iostream>

FullyConnectedLayer::FullyConnectedLayer(int numberOfNeurons) : Layer1D(numberOfNeurons)
{
}

void FullyConnectedLayer::print()
{
	Layer1D::print();
	std::cout << "    FullyConnectedLayer" << std::endl;
}
