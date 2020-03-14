#include "Vector.h"
#include "Exceptions.h"

Vector::Vector(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int vectorHeight)
	: Container{neuronFactory, neuronsConnectingStrategy },
	vectorHeight{ vectorHeight }
{
	for(int i = 0; i < vectorHeight; i++)
		row.push_back(std::move(neuronFactory.createNeuron()));
}

int Vector::getVectorHeight()
{
	return vectorHeight;
}

Neuron& Vector::getNeuron(unsigned int index)
{
	if (index < row.size())
		return *row[index];
	else throw ContainerOutOfRangeException{};
}

unsigned int Vector::getNumberOfNeurons()
{
	return vectorHeight;
}
