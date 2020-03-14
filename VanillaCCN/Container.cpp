#include "Container.h"

Container::Container(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy)
	: neuronsConnectingStrategy{ neuronsConnectingStrategy },
	neuronFactory {neuronFactory}
{
}

void Container::connect(Container& preceedingContainer)
{
	neuronsConnectingStrategy.connect(*this, preceedingContainer);
}
