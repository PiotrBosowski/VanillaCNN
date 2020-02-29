#pragma once
#include "Layer.h"
#include <vector>
#include "Connection.h"
#include <memory>

class NeuralNetwork
{
public:
	NeuralNetwork();

private:
	std::vector<std::unique_ptr<Layer>> layers;
	std::vector<std::unique_ptr<Connection>> connections;
public:

public:
	void addLayer(Layer* newLayer); //then transformed into unique_ptr
	void compile();
	void print();

private:
	void populateLayers();
	void connectLayers();
};

