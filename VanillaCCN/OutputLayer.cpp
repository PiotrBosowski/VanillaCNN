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

void OutputLayer::populateNeurons()
{
	throw std::exception{ "bad outputlayer init: it cannot be first layer" };
}

void OutputLayer::connect(Layer& previousLayer)
{
	OutputLayerConnector(*this).connect(previousLayer);
}