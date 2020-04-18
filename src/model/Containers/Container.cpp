//
// Created by piotr on 20/04/11.
//

#include "Container.h"
#include "../exceptions/Exceptions.h"

Neuron& Container::getNeuron(unsigned int index)
{
    if (index < neurons.size())
        return *neurons[index];
    else throw ContainerOutOfRangeException{};
}

unsigned int Container::getNumberOfNeurons() {
    return neurons.size();
}

std::ostream &operator<<(std::ostream &os, const Container &container) {
    os << "neurons: " << container.neurons.size();
    return os;
}
