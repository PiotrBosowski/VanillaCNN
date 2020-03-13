#pragma once
#include "ContainersConnectingStrategy.h"

class ContainersConnecting1toRandom : public ContainersConnectingStrategy
{
public:
	ContainersConnecting1toRandom(Layer & previousLayer);
	virtual void connect(Layer & previousLayer);
};
