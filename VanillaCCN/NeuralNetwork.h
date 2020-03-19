#pragma once
#include <memory>
#include <vector>
#include "Exceptions.h"
#include "Layer.h"
#include "OutputSource.h"

class NeuralNetwork : public OutputSource
{
public:
	NeuralNetwork(bool printingEnabled = true);

private:
	std::vector<std::shared_ptr<Layer>> layers;
public:
	void addLayer(Layer* newLayer);
	void compile();
	const std::vector<std::shared_ptr<Layer>>& getOutput() const override;

private:
	void registerPreceedingLayers();
	void populateLayers();
	void connectLayers();
};
