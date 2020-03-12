#include "Vector.h"

Vector::Vector(int vectorHeight)
	:vectorHeight{ vectorHeight }
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

void Vector::connect(Container& preceeding)
{
}
