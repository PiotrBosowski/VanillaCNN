#pragma once
#include "Layer.h"

class ContainersConnectingStrategy
{
public:
	ContainersConnectingStrategy(Layer& sourceLayer);

protected:
	Layer& sourceLayer;

public:
	virtual void connect(Layer& previousLayer) = 0;
};
