#include "NeuralNetwork.h"
#include <time.h>
#include <stdlib.h>
#include <memory>
#include <iostream>
#include "Exceptions.h"
#include "ConsolePrinter.h"


NeuralNetwork::NeuralNetwork(bool printingEnabled)
	: printer{ std::make_unique<ConsolePrinter>(*this, printingEnabled) }
{
	srand((unsigned int)time(NULL));
}

void NeuralNetwork::addLayer(Layer * layer)
{
	try
	{
		if (layer == nullptr) //checks if null also
			throw LayerCreatingException("ERROR: Bad Layer initialization, nothing was added.");
		layers.push_back(std::shared_ptr<Layer>(layer));
	}
	catch (const std::exception & ex)
	{
		printer->printError(ex.what());
	}
}

const std::vector<std::shared_ptr<Layer>>& NeuralNetwork::getStructure() const
{
	return layers;
}

void NeuralNetwork::compile()
{
	try
	{
		registerPreceedingLayers();
		printer->print("After registering preceeding layers:");
		populateLayers();
		printer->print("After populating layers:");
		connectLayers();
		printer->print("After connecting layers:");
	}
	catch (const std::exception & ex)
	{
		printer->printError(ex.what());
	}
	catch (...)
	{
		printer->printError("Unknown error.");
	}
}

void NeuralNetwork::registerPreceedingLayers()
{
	if (layers.size() < 2) throw ConnectingException{ "not enough layers to make preceeding layers registration" };
	for (unsigned int i = 1; i < layers.size(); i++)
	{
		layers[i]->setPreviousLayer(layers[i - 1]);
	}
}

void NeuralNetwork::populateLayers()
{
	if (layers.empty()) throw PopulatingException{ "no layers to populate" };
	for (auto& layer : layers)
		layer->createContainers();
}

void NeuralNetwork::connectLayers()
{
	if (layers.size() < 2) throw ConnectingException{ "no layers to connect" };
	for (auto& layer : layers)
		layer->connectToPreceeding();
}