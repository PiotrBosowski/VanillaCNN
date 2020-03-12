#include "ConvolutionLayerConnector.h"
#include "FullyConnectedLayer.h"
#include "InputLayer.h"
#include "ConvolutionLayer.h"
#include "DownsamplingLayer.h"

ConvolutionLayerConnector::ConvolutionLayerConnector(ConvolutionLayer& sourceLayer)
	: sourceLayer{sourceLayer}
{
}

void ConvolutionLayerConnector::connect(Layer& precedingLayer)
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

void ConvolutionLayerConnector::toInputLayer(InputLayer& preceedingLayer)
{
	for (auto& sourceMatrix : sourceLayer.getMatrices())
	{
		for (auto& preceedingMatrix : preceedingLayer.getMatrices())
		{
			sourceMatrix->connect(*preceedingMatrix);
		}
	}
}

void ConvolutionLayerConnector::toConvolutionLayer(ConvolutionLayer& preceedingLayer)
{
	for (auto& sourceMatrix : sourceLayer.getMatrices())
	{
		for (auto& preceedingMatrix : preceedingLayer.getMatrices())
		{
			sourceMatrix->connect(*preceedingMatrix);
		}
	}
}

void ConvolutionLayerConnector::toDownsamplingLayer(DownsamplingLayer& preceedingLayer)
{
	for (auto& sourceMatrix : sourceLayer.getMatrices())
	{
		for (auto& preceedingMatrix : preceedingLayer.getMatrices())
		{
			sourceMatrix->connect(*preceedingMatrix);
		}
	}
}
