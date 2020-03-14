#include "Vector.h"

Vector::Vector(NeuronsConnectingStrategy& neuronsConnectingStrategy, int vectorHeight)
	: Container{ neuronsConnectingStrategy },
	vectorHeight{ vectorHeight }
{
}

int Vector::getVectorHeight()
{
	return vectorHeight;
}

Neuron& Vector::getNeuron(unsigned int index)
{
	return *row[index];
}

void Vector::addNeuron(std::unique_ptr<Neuron> newNeuron)
{
	row.push_back(std::move(newNeuron)); //TODO move()
}

void Vector::populateContainer(const Neuron& source, int width, int height)
{
}

void Vector::connect(Container& preceeding)
{
}
