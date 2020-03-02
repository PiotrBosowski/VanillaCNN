#include "NeuronConv.h"
#include <functional>

NeuronConv::NeuronConv(FeatureDetector & featureDetector)
	: featureDetector {featureDetector}
{
}

void NeuronConv::acceptConnection(Neuron & preceding)
{
	connections.push_back(preceding); //TODO: dont have to implicitly call reference_wrapper construcor (or at least seems so Xdd)
}

void NeuronConv::calculateValue()
{
	value = 0;
	for (unsigned int i = 0; i < connections.size(); i++)
	{
		value += connections[i].get().getValue() * featureDetector.getFeatureWeight(i);
	}
	//apply activation function...
}
