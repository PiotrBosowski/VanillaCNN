#pragma once
#include "ContainersConnectingStrategy.h"

class ContainersConnecting1to1 : public ContainersConnectingStrategy
{
public:
	ContainersConnecting1to1(Layer& previousLayer);
	virtual void connect(Layer& previousLayer);
};

