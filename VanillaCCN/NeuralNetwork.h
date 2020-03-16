#pragma once
#include "Layer.h"
#include <vector>
#include <memory>
#include "OutputSource.h"
#include "OutputPrinter.h"

class NeuralNetwork : public OutputSource
{
public:
	NeuralNetwork(bool printingEnabled = true);

private:
	std::vector<std::shared_ptr<Layer>> layers;
	std::unique_ptr<OutputPrinter> printer;
public:
	void addLayer(Layer* newLayer); //then transformed into unique_ptr
	void compile();
	const std::vector<std::shared_ptr<Layer>>& getStructure() const override;

private:
	void registerPreceedingLayers();
	void populateLayers();
	void connectLayers();
};
