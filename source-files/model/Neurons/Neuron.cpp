//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"

double Neuron::getValue()
{
    return value;
}

void Neuron::connect(Neuron & preceding)
{
    connections.add(preceding);
}