#include "DownsamplingLayerConnector.h"
#include "InputLayer.h"
#include "ConvolutionLayer.h"
#include "DownsamplingLayer.h"

DownsamplingLayerConnector::DownsamplingLayerConnector(DownsamplingLayer& sourceLayer)
	: sourceLayer{ sourceLayer }
{
}

void DownsamplingLayerConnector::connect(Layer& precedingLayer)
{
	if (auto layer = dynamic_cast<InputLayer*>(&precedingLayer))
	{
		toInputLayer(*layer);
	}
	else if (auto layer = dynamic_cast<ConvolutionLayer*>(&precedingLayer))
	{
		toConvolutionLayer(*layer);
	}
	else if (auto layer = dynamic_cast<DownsamplingLayer*>(&precedingLayer))
	{
		toDownsamplingLayer(*layer);
	}
	else
	{
		reportError(precedingLayer);
	}
}

void DownsamplingLayerConnector::toInputLayer(InputLayer& preceedingLayer)
{
	auto numberOfMatrices = sourceLayer.getNumberOfMatrices();
	for (int i = 0; i < numberOfMatrices; i++)
	{
		sourceLayer.getMatrices()[i]->connect(*preceedingLayer.getMatrices()[i]);
	}
}

void DownsamplingLayerConnector::toConvolutionLayer(ConvolutionLayer& preceedingLayer)
{
	auto numberOfMatrices = sourceLayer.getNumberOfMatrices();
	for (int i = 0; i < numberOfMatrices; i++)
	{
		sourceLayer.getMatrices()[i]->connect(*preceedingLayer.getMatrices()[i]);
	}
}

void DownsamplingLayerConnector::toDownsamplingLayer(DownsamplingLayer& preceedingLayer)
{
	auto numberOfMatrices = sourceLayer.getNumberOfMatrices();
	for (int i = 0; i < numberOfMatrices; i++)
	{
		sourceLayer.getMatrices()[i]->connect(*preceedingLayer.getMatrices()[i]);
	}
}
