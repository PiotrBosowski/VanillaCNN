//
// Created by piotr on 20/04/11.
//


#ifndef VANILLACNN_CLION_NEURON_H
#define VANILLACNN_CLION_NEURON_H
#include <ostream>
#include <vector>
#include <random>
#include "Connections/Connection.h"

/**
@brief Base class for all neuron types.
@details Neuron class tries to mimic real nerve cell.
It is connected to other neurons, these connections has randomly-initialized weights.
Learning process is all about adjusting weights' values in a process called back propagation.
@version 1.0*/
class Neuron
{
protected:
    /**
    @brief Stores Neuron's connections. Weights are stored separately, since the way of storing them depends on Neuron type.*/
    std::vector<std::unique_ptr<Connection>> connections;

    /**
    @brief Stores Neuron's current value.*/
    double value;


    static double getRandomWeight();


public:
    /**
    @brief Neuron's value getter.
    @return returns Neuron's /c value*/
    [[nodiscard]] double getValue() const;

    Neuron();

    /**
    @brief Adds a connection to preceeding Neuron to @c this->Neuron::connections.
    @arg @c preceding - Reference to the preceding Neuron.*/
    virtual void acceptConnection(std::unique_ptr<Connection> connection);

    /**
    @brief Calculates new Neuron's value and stores it in Neuron::value.*/
    void calculateValue();

    /**
    @brief Returns number of Neuron's Connections.
    @return returns number of Neuron's Connections. */
    int getNumberOfConnections();

};

#endif //VANILLACNN_CLION_NEURON_H