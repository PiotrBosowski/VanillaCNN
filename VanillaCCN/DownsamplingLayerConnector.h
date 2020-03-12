#pragma once
#include "Layer.h"
#include "Connector.h"

class InputLayer;
class ConvolutionLayer;
class DownsamplingLayer;

class DownsamplingLayerConnector : public Connector
{
public:
	DownsamplingLayerConnector(DownsamplingLayer& sourceLayer);
	void connect(Layer& previousLayer) override;

private:
	DownsamplingLayer& sourceLayer;
	void toInputLayer(InputLayer&);
	void toConvolutionLayer(ConvolutionLayer&);
	void toDownsamplingLayer(DownsamplingLayer&);
};

