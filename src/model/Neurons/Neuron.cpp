//
// Created by piotr on 20/04/11.
//

#include "Neuron.h"


Neuron::Neuron()
: value{getRandomWeight()}
{
}


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

double Neuron::getRandomWeight() {
    static std::mt19937 rng{std::random_device()()};
    static std::uniform_real_distribution uni(0.10, 1.0);
    return uni(rng);
}

