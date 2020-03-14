#include "ContainersConnecting1toAll.h"
#include "Layer.h"

ContainersConnecting1toAll::ContainersConnecting1toAll(Layer& sourceLayer)
	: ContainersConnectingStrategy{sourceLayer}
{
}

void ContainersConnecting1toAll::connect(Layer& previousLayer)
{
	auto& sourceContainers = sourceLayer.getContainers();
	auto& previousContainers = previousLayer.getContainers();
	for (auto& sourceContainer : sourceContainers)
	{
		for (auto& previousContainer : previousContainers)
		{
			sourceContainer->connect(*previousContainer);
		}
	}
}
