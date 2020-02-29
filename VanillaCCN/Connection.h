#pragma once
#include <memory>

class Neuron; //included in cpp file

class Connection
{
public:
	//Connection(const Connection & a) = delete;
	Connection(std::unique_ptr<Neuron>& preceding, std::unique_ptr<Neuron>& following);
private: 
	std::unique_ptr<Neuron>& preceding;
	std::unique_ptr<Neuron>& following;
	double weight;
};

