#include "ContainersConnecting1toRandom.h"
#include "Layer.h"

ContainersConnecting1toRandom::ContainersConnecting1toRandom(Layer& previousLayer)
	: ContainersConnectingStrategy{ previousLayer }
{
}

void ContainersConnecting1toRandom::connect(Layer& previousLayer)
{
	auto& sourceContainers = sourceLayer.getContainers();
	auto& previousContainers = previousLayer.getContainers();
	//TODO 1 to random
}
