#pragma once
#include "Layer.h"
#include <vector>
#include <memory>

class NeuralNetwork
{
public:
	NeuralNetwork(bool printEnabled = true);

private:
	std::vector<std::unique_ptr<Layer>> layers;
	bool printEnabled;

public:
	void addLayer(Layer* newLayer); //then transformed into unique_ptr
	void compile();

private:
	void populateLayers();
	void connectLayers();
	void print(std::string description = "");
	void printError(std::string error);
};
