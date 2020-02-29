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

void DownsamplingLayer::populateNeurons(std::unique_ptr<Layer>& previousLayer)
{
	Layer2D* previousLayer2D = static_cast<Layer2D*>(previousLayer.get());
	this->matrixHeight = previousLayer2D->getMatrixHeight() / this->getDownsamplerHeight(); //(31 -> 15 etc.) 
	this->matrixWidth = previousLayer2D->getMatrixWidth() / this->getDownsamplerWidth();
	this->numberOfMatrices = previousLayer2D->getNumberOfMatrices();
	matrices = std::vector<std::unique_ptr<Matrix>>();
	for (int h = 0; h < numberOfMatrices; h++)
		matrices.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
}

void DownsamplingLayer::print()
{
	Layer2D::print();
	std::cout << "    DownsamplingLayer: downsamplerHeight(" << downsamplerHeight << "), downsamplerWidth(" << downsamplerWidth << ")" << std::endl;
}

DownsamplingLayer::~DownsamplingLayer()
{
}
