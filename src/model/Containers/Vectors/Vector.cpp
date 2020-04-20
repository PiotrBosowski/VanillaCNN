//
// Created by piotr on 20/04/11.
//


#include "Vector.h"

Vector::Vector(int vectorHeight)
          : vectorHeight{ vectorHeight }
{
    for(int i = 0; i < vectorHeight; i++)
        neurons.push_back(std::make_unique<Neuron>());
}
