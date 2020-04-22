//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"

double Neuron::getValue() const
{
    return value;
}

void Neuron::acceptConnection(std::unique_ptr<Connection> connection) {
    connections.emplace_back(std::move(connection));
}

void Neuron::calculateValue() {
    // depends on layer type
}

int Neuron::getNumberOfConnections() {
    return connections.size();
}

Neuron::Neuron(double init) : value(init) {}
