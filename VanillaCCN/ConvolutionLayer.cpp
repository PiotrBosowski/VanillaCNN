#include "ConvolutionLayer.h"
#include <iostream>
#include "TBDMarkerEnum.h"
#include <vector>

int ConvolutionLayer::getFeatureDetectorHeight()
{
	return featureDetectorHeight;
}

int ConvolutionLayer::getFeatureDetectorWidth()
{
	return featureDetectorWidth;
}

ConvolutionLayer::ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
	: Layer2D(numberOfFeatureDetectors, TBD, TBD), featureDetectorHeight{ featureDetectorHeight }, featureDetectorWidth{ featureDetectorWidth }
{
	if (featureDetectorHeight < 1 || featureDetectorWidth < 1) throw std::exception("ERROR: bad ConvolutionLayer initialization");
}

void ConvolutionLayer::populateNeurons(std::unique_ptr<Layer>& previousLayer)
{
	matrixHeight = static_cast<Layer2D*>(previousLayer.get())->getMatrixHeight() - (this->getFeatureDetectorHeight() / 2) * 2; //(5 -> 4 etc.) 
	matrixWidth = static_cast<Layer2D*>(previousLayer.get())->getMatrixWidth() - (this->getFeatureDetectorWidth() / 2) * 2;
	matrices = std::vector<std::unique_ptr<Matrix>>();
	for (int h = 0; h < numberOfMatrices; h++)
		matrices.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
}

void ConvolutionLayer::print()
{
	Layer2D::print();
	std::cout << "    ConvolutionLayer, featureDetectorHeight(" << featureDetectorHeight << "), featureDetectorWidth(" << featureDetectorWidth << "), mode(" << mode << ")" << std::endl;
}

