#pragma once
#include "Layer.h"

class FullyConnectedLayer;

class FullyConnectedLayerConnector
{
public:
	FullyConnectedLayerConnector(FullyConnectedLayer& sourceLayer);
	void connect(Layer& previousLayer);
	
private:
	FullyConnectedLayer& sourceLayer;
};

