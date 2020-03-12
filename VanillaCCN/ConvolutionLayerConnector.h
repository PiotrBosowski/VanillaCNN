#pragma once
#include "Connector.h"

class ConvolutionLayer;
class InputLayer;
class DownsamplingLayer;

class ConvolutionLayerConnector : public Connector	
{
public:
	ConvolutionLayerConnector(ConvolutionLayer& sourceLayer);
	void connect(Layer& previousLayer) override;
private:
	void toInputLayer(InputLayer&);
	void toConvolutionLayer(ConvolutionLayer&);
	void toDownsamplingLayer(DownsamplingLayer&);
	ConvolutionLayer& sourceLayer;
};
