#include "FullyConnectedLayerConnector.h"
#include "FullyConnectedLayer.h"
#include "InputLayer.h"
#include "ConvolutionLayer.h"
#include "DownsamplingLayer.h"

FullyConnectedLayerConnector::FullyConnectedLayerConnector(FullyConnectedLayer& sourceLayer)
	: sourceLayer{sourceLayer}
{
}

void FullyConnectedLayerConnector::connect(Layer& precedingLayer)
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

void FullyConnectedLayerConnector::toFullyConnectedLayer(FullyConnectedLayer& preceedingLayer) //every preceeding neuron connected with every following neuron
{
	sourceLayer.getNeurons().connect(preceedingLayer.getNeurons());
}

void FullyConnectedLayerConnector::toInputLayer(InputLayer& preceedingLayer) //TODO -> input layer only 1 matrix ????????
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}

void FullyConnectedLayerConnector::toConvolutionLayer(ConvolutionLayer& preceedingLayer) //connects local vector to all matrices in preceeding layer
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}


void FullyConnectedLayerConnector::toDownsamplingLayer(DownsamplingLayer& preceedingLayer) //connects local vector to all matrices in preceeding layer
{
	for (auto& matrix : preceedingLayer.getMatrices())
		sourceLayer.getNeurons().connect(*matrix);
}
