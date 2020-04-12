//
// Created by piotr on 20/04/11.
//


#include "Vector.h"
#include "../../exceptions/Exceptions.h"

Vector::Vector(NeuronsFactory& neuronFactory, int vectorHeight)
          : vectorHeight{ vectorHeight }
{
    for(int i = 0; i < vectorHeight; i++)
        row.push_back(neuronFactory.createNeuron());
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
