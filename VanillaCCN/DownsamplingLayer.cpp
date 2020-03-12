#include "DownsamplingLayer.h"
#include <iostream>
#include "NeuralNetwork.h"
#include "TBDMarkerEnum.h"
#include <vector>

int DownsamplingLayer::getDownsamplerHeight()
{
	return downsamplerHeight;
}

int DownsamplingLayer::getDownsamplerWidth()
{
	return downsamplerWidth;
}

DownsamplingLayer::DownsamplingLayer(int downsamplerHeight, int downsamplerWidth)
	: Layer2D(TBD, TBD, TBD), downsamplerHeight{ downsamplerHeight }, downsamplerWidth{ downsamplerWidth }
{
	if (downsamplerHeight < 1 || downsamplerWidth < 1) throw std::exception("ERROR: bad DownsamplingLayer initialization");
}

void DownsamplingLayer::populateNeurons(Layer& previousLayer)
{
	Layer2D& previousLayer2D = static_cast<Layer2D&>(previousLayer);
	this->matrixHeight = previousLayer2D.getMatrixHeight() / this->getDownsamplerHeight(); //(31 -> 15 etc.) 
	this->matrixWidth = previousLayer2D.getMatrixWidth() / this->getDownsamplerWidth();
	this->numberOfMatrices = previousLayer2D.getNumberOfMatrices();
	matrices = std::vector<std::unique_ptr<Matrix>>();
	for (int h = 0; h < numberOfMatrices; h++)
		matrices.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
}

void DownsamplingLayer::populateNeurons()
{
	throw std::exception{ "bad downsampling layer initialization: it cannot be the first layer of the network!" };
}

std::string DownsamplingLayer::getSummary()
{
	std::string result = Layer2D::getSummary() + "\t\tDownsamplingLayer: downsamplerHeight(" + std::to_string(downsamplerHeight)
		+ "), downsamplerWidth(" + std::to_string(downsamplerWidth) + ")\n";
	return result;
}

void DownsamplingLayer::connect(Layer& previousLayer)
{
	DownsamplingLayerConnector(*this).connect(previousLayer);	
}

DownsamplingLayer::~DownsamplingLayer()
{
}
