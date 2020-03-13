#pragma once
#include "ContainersConnectingStrategy.h"

class ContainersConnecting1toAll : public ContainersConnectingStrategy
{
public:
	ContainersConnecting1toAll(Layer& sourceLayer);
	void connect(Layer& previousLayer) override;
};

