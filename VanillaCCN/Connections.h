#pragma once
#include <vector>
#include <functional>

class Neuron;

class Connections
{
private:
	std::vector<std::reference_wrapper<Neuron>> connections;
public:
	void add(Neuron& newConnection);
	int size();
	const Neuron& get(int index);
	double getValue(int index);
};