#include "OutputLayerConnector.h"
#include "OutputLayer.h"
#include "FullyConnectedLayer.h"
#include "InputLayer.h"
#include "ConvolutionLayer.h"
#include "DownsamplingLayer.h"

OutputLayerConnector::OutputLayerConnector(OutputLayer& sourceLayer)
	: sourceLayer{sourceLayer}
{
}

void OutputLayerConnector::connect(Layer& precedingLayer)
{
	if (auto layer = dynamic_cast<FullyConnectedLayer*>(&precedingLayer))
	{
		toFullyConnectedLayer(*layer);
	}
	else if (auto layer = dynamic_cast<InputLayer*>(&precedingLayer))
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

void OutputLayerConnector::toFullyConnectedLayer(FullyConnectedLayer& preceedingLayer)
{
	sourceLayer.getNeurons().connect(preceedingLayer.getNeurons());
}

void OutputLayerConnector::toInputLayer(InputLayer& preceedingLayer)
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}

void OutputLayerConnector::toConvolutionLayer(ConvolutionLayer& preceedingLayer)
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}

void OutputLayerConnector::toDownsamplingLayer(DownsamplingLayer& preceedingLayer)
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}
