#pragma once
#include "NeuronsConnectingStrategy.h"
#include "Container.h"

class NeuronsConnecting1toArea : public NeuronsConnectingStrategy
{
public:
	NeuronsConnecting1toArea(int areaHeight, int areaWidth);
	void connect(Container& sourceContainer, Container& previousContainer) override;

private:
	int areaHeight;
	int areaWidth;
};

