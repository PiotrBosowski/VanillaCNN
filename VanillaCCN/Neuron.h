#pragma once
#include <vector>
#include "Connections.h"


/**
@brief Base class for all neuron types.
@details 
@version 1.0*/
class Neuron
{
protected:
	/**
	@brief Stores Neuron's connections. Weights are stored separately, since the way of storing them depends on Neuron type.*/
	Connections connections;

	/**
	@brief Stores Neuron's current value.*/
	double value = 0;

public:
	/**
	@brief Neuron's value getter.
	@return returns Neuron's /c value*/
	double getValue();  

	/**
	@brief Adds a connection to preceeding Neuron to @c this->Neuron::connections.
	@arg @c preceding - Reference to the preceding Neuron.*/
	virtual void connect(Neuron& preceding);

	/**
	@brief Calculates new Neuron's value and stores it in Neuron::value.*/
	virtual void calculateValue() = 0;
};