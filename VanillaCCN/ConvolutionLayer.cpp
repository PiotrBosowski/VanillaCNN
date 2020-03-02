#include "ConvolutionLayer.h"
#include <iostream>
#include "TBDMarkerEnum.h"
#include <vector>
#include "MatrixConv.h"

ConvolutionLayer::ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
	: Layer2D(numberOfFeatureDetectors, TBD, TBD), featureDetectorHeight{ featureDetectorHeight }, featureDetectorWidth{ featureDetectorWidth }
{
	if (featureDetectorHeight < 1 || featureDetectorWidth < 1) throw std::exception("ERROR: bad ConvolutionLayer initialization");
	//featureDetectors = std::vector<FeatureDetector>(numberOfFeatureDetectors, FeatureDetector{ featureDetectorHeight, featureDetectorWidth });
}

int ConvolutionLayer::getFeatureDetectorHeight()
{
	return featureDetectorHeight;
}

int ConvolutionLayer::getFeatureDetectorWidth()
{
	return featureDetectorWidth;
}

void ConvolutionLayer::populateNeurons(Layer& previousLayer)
{
	matrixHeight = static_cast<Layer2D&>(previousLayer).getMatrixHeight() - (this->getFeatureDetectorHeight() / 2) * 2; //(5 -> 4 etc.) 
	matrixWidth = static_cast<Layer2D&>(previousLayer).getMatrixWidth() - (this->getFeatureDetectorWidth() / 2) * 2;
	matrices = std::vector<std::unique_ptr<Matrix>>();
	for (int h = 0; h < numberOfMatrices; h++)
		matrices.push_back(std::make_unique<MatrixConv>(matrixHeight, matrixWidth));
}

void ConvolutionLayer::populateNeurons()
{
	throw std::exception{ "convolution layer bad initialization - it cannot be the first layer of the network!" };
}

void ConvolutionLayer::print()
{
	Layer2D::print();
	std::cout << "    ConvolutionLayer, featureDetectorHeight(" << featureDetectorHeight << "), featureDetectorWidth(" << featureDetectorWidth << ")" << std::endl;
}

