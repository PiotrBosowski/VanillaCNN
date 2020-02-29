#pragma once
#include <memory>

class Neuron; //included in cpp file

class Connection
{
public:
	Connection(std::unique_ptr<Neuron>& first, std::unique_ptr<Neuron>& second);
private: 
	std::unique_ptr<Neuron> first;
	std::unique_ptr<Neuron> second;
	double weight;
};

