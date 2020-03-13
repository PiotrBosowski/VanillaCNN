#include "ConvolutionLayer.h"
#include "ContainersConnecting1toAll.h"
#include "NeuronsConnecting1toAll.h"
#include <iostream>
#include "TBDMarkerEnum.h"
#include <vector>
#include "MatrixConv.h"
#include <string>
#include "Exceptions.h"

ConvolutionLayer::ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth)
	: Layer2D(numberOfFeatureDetectors, TBD, TBD),
	featureDetectorHeight{ featureDetectorHeight },
	featureDetectorWidth{ featureDetectorWidth }
{
	if (featureDetectorHeight < 1 || featureDetectorWidth < 1) throw LayerCreatingException("ERROR: bad ConvolutionLayer initialization");
	containersConnectingStrategy = std::make_unique<ContainersConnecting1toAll>(*this);  //ContainersConnecting1toRandom -> 1 to all atm
	neuronsConnectingStrategy = std::make_unique<NeuronsConnecting1toAll>();
}

int ConvolutionLayer::getFeatureDetectorHeight()
{
	return featureDetectorHeight;
}

int ConvolutionLayer::getFeatureDetectorWidth()
{
	return featureDetectorWidth;
}

void ConvolutionLayer::createContainers()
{
	try
	{
		Layer2D& previousLayer2D = dynamic_cast<Layer2D&>(*previousLayer);
		matrixHeight = previousLayer2D.getMatrixHeight() - (this->getFeatureDetectorHeight() / 2) * 2; //(5 -> 4 etc.) 
		matrixWidth = previousLayer2D.getMatrixWidth() - (this->getFeatureDetectorWidth() / 2) * 2;
		for (int i = 0; i < numberOfContainers; i++)
			containers.push_back(std::make_unique<Matrix>(matrixHeight, matrixWidth));
	}
	catch (const std::bad_cast& _)
	{
		throw LayerCreatingException{"cannot attach convolution layer to non-2D layer"};
	}
}

std::string ConvolutionLayer::getSummary()
{
	std::string result = Layer2D::getSummary() + "\t\tConvolutionLayer, featureDetectorHeight(" + std::to_string(featureDetectorHeight)
		+ "), featureDetectorWidth(" + std::to_string(featureDetectorWidth) + ")\n";
	return result;
}

