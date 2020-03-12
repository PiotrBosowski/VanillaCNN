#pragma once
#include "Layer.h"
#include <vector>
#include <memory>
#include "ConsolePrinter.h"

class NeuralNetwork
{
public:
	NeuralNetwork(bool printingEnabled = true);

private:
	std::vector<std::unique_ptr<Layer>> layers;
	std::unique_ptr<ConsolePrinter> printer;
public:
	void addLayer(Layer* newLayer); //then transformed into unique_ptr
	const std::vector<std::unique_ptr<Layer>>& getStructure() const;
	void compile();

private:
	void populateLayers();
	void connectLayers();
};
