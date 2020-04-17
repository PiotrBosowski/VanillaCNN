//
// Created by piotr on 20/04/11.
//


#include "Vector.h"
#include "../../exceptions/Exceptions.h"

Vector::Vector(NeuronsFactory& neuronFactory, int vectorHeight)
          : vectorHeight{ vectorHeight }
{
    for(int i = 0; i < vectorHeight; i++)
        neurons.push_back(neuronFactory.createNeuron());
}

int Vector::getVectorHeight()
{
    return vectorHeight;
}