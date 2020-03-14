#include "DownsamplingLayer.h"
#include <iostream>
#include "NeuralNetwork.h"
#include "TBDMarkerEnum.h"
#include <vector>
#include "Exceptions.h"
#include "ContainersConnecting1to1.h"
#include "NeuronsConnecting1toArea.h"
#include "WeightedNeuronFactory.h"


DownsamplingLayer::DownsamplingLayer(int downsamplerHeight, int downsamplerWidth) //create prototype layer to avoid things like this TBD TBD TBD TODO
	: Layer2D(TBD, TBD, TBD), downsamplerHeight{ downsamplerHeight }, downsamplerWidth{ downsamplerWidth }
{
	if (downsamplerHeight < 1 || downsamplerWidth < 1) throw LayerCreatingException("ERROR: bad DownsamplingLayer initialization");
	containersConnectingStrategy = std::make_unique<ContainersConnecting1to1>(*this);  //ContainersConnecting1toRandom -> 1 to all atm
	neuronsConnectingStrategy = std::make_unique<NeuronsConnecting1toArea>(downsamplerHeight, downsamplerWidth);
	neuronFactory = std::make_unique<WeightedNeuronFactory>();
}

int DownsamplingLayer::getDownsamplerHeight()
{
	return downsamplerHeight;
}

int DownsamplingLayer::getDownsamplerWidth()
{
	return downsamplerWidth;
}

void DownsamplingLayer::createContainers()
{
	try
	{
		Layer2D& previousLayer2D = dynamic_cast<Layer2D&>(*previousLayer);
		numberOfContainers = previousLayer->getNumberOfContainers();
		matrixHeight = previousLayer2D.getMatrixHeight() / this->getDownsamplerHeight();
		matrixWidth = previousLayer2D.getMatrixWidth() / this->getDownsamplerWidth();
		for (int h = 0; h < numberOfContainers; h++)
			containers.push_back(std::make_unique<Matrix>(*neuronFactory, *neuronsConnectingStrategy, matrixHeight, matrixWidth));
	}
	catch (const std::bad_cast & _)
	{
		throw LayerCreatingException{ "cannot attach downsampling layer to non-2D layer" };
	}
}

std::string DownsamplingLayer::getSummary()
{
	std::string result = Layer2D::getSummary() + "\t\tDownsamplingLayer: downsamplerHeight(" + std::to_string(downsamplerHeight)
		+ "), downsamplerWidth(" + std::to_string(downsamplerWidth) + ")\n";
	return result;
}
