//
// Created by piotr on 20/04/11.
//

#include "Container.h"
#include "Neurons/Neuron.h"
#include "Exceptions/Exceptions.h"

Neuron& Container::getNeuron(unsigned int index)
{
    if (index < neurons.size())
        return *neurons[index];
    else throw ContainerOutOfRangeException{};
}

unsigned int Container::getNumberOfNeurons() {
    return neurons.size();
}

Container::Container(int numberOfNeurons)
{
    if(numberOfNeurons < 0) throw ContainersCreatingException("cannot create container with negative number of neurons");
    for(int i = 0; i < numberOfNeurons; i++)
        neurons.push_back(std::make_unique<Neuron>());
}
