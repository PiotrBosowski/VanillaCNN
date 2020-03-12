#pragma once
#include "Layer.h"
#include "Connector.h"

class FullyConnectedLayer;
class InputLayer;
class ConvolutionLayer;
class DownsamplingLayer;

class FullyConnectedLayerConnector : public Connector
{
public:
	FullyConnectedLayerConnector(FullyConnectedLayer& sourceLayer);
	void connect(Layer& previousLayer);

private:
	FullyConnectedLayer& sourceLayer;
	void toFullyConnectedLayer(FullyConnectedLayer&);
	void toInputLayer(InputLayer&);
	void toConvolutionLayer(ConvolutionLayer&);
	void toDownsamplingLayer(DownsamplingLayer&);
};
