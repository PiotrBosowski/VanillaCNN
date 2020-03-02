#pragma once
#include "Layer.h"
#include <vector>
#include <memory>

class NeuralNetwork
{
public:
	NeuralNetwork();

private:
	std::vector<std::unique_ptr<Layer>> layers;

public:
	void addLayer(Layer* newLayer); //then transformed into unique_ptr
	void compile();
	void print();

private:
	void populateLayers();
	void connectLayers();
};

