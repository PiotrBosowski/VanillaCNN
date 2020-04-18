//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"

double Neuron::getValue() const
{
    return value;
}

void Neuron::acceptConnection(std::unique_ptr<Connection> connection) {
    connections.add(std::move(connection));
}

void Neuron::calculateValue() {

}
