#pragma once
#include "NeuronsConnectingStrategy.h"
#include "Container.h"

class NeuronsConnecting1toAll : public NeuronsConnectingStrategy
{
public:
	void connect(Container& sourceContainer, Container& previousContainer) override;
};
