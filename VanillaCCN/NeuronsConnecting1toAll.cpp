#include "NeuronsConnecting1toAll.h"
#include "Neuron.h"

void NeuronsConnecting1toAll::connect(Container& sourceContainer, Container& previousContainer)
{
	for (int i = 0; i < sourceContainer.getNumberOfNeurons(); i++) //TODO: iterator / for all neurons in container
	{
		Neuron& sourceNeuron = sourceContainer.getNeuron(i);
		for (int j = 0; j < previousContainer.getNumberOfNeurons(); j++)
		{
			Neuron& previousNeuron = previousContainer.getNeuron(j);
			sourceNeuron.connect(previousNeuron);
		}
	}
}
