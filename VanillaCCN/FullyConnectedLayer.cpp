#include "FullyConnectedLayer.h"
#include <iostream>

FullyConnectedLayer::FullyConnectedLayer(int numberOfNeurons) : Layer1D(numberOfNeurons)
{
}

void FullyConnectedLayer::populateNeurons()
{
	throw std::exception{ "bad fully connected layer init: it cannot be initialized without any layers before!" };
}

void FullyConnectedLayer::print()
{
	Layer1D::print();
	std::cout << "    FullyConnectedLayer" << std::endl;
}
