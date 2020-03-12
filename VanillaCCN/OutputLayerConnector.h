#pragma once
#include "Connector.h"

class OutputLayer;
class FullyConnectedLayer;
class InputLayer;
class ConvolutionLayer;
class DownsamplingLayer;

class OutputLayerConnector : public Connector
{
public:
	OutputLayerConnector(OutputLayer& sourceLayer);
	void connect(Layer& previousLayer) override;

private:
	void toFullyConnectedLayer(FullyConnectedLayer&);
	void toInputLayer(InputLayer&);
	void toConvolutionLayer(ConvolutionLayer&);
	void toDownsamplingLayer(DownsamplingLayer&);
	OutputLayer& sourceLayer;
};
