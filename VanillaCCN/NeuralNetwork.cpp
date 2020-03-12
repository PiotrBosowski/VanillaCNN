#include "NeuralNetwork.h"
#include <time.h>
#include <stdlib.h>
#include <memory>
#include <iostream>



NeuralNetwork::NeuralNetwork(bool printingEnabled)
	: printer{ std::make_unique<ConsolePrinter>(*this, printingEnabled) }
{
	srand((unsigned int)time(NULL));
}

void NeuralNetwork::addLayer(Layer * layer)
{
	try
	{
		if (!dynamic_cast<Layer*>(layer)) //checks if null also
			throw std::exception("ERROR: Bad Layer initialization, nothing was added.");
		//layers.push_back(std::move(std::unique_ptr<Layer>(layer))); //has to be like this because, cant transform to make_unique; this doesnt work: std::unique_ptr<Layer> newLayer = std::unique_ptr<Layer>(layer);
		layers.push_back(std::unique_ptr<Layer>(layer)); //has to be like this because, cant transform to make_unique; this doesnt work: std::unique_ptr<Layer> newLayer = std::unique_ptr<Layer>(layer);
	}
	catch (const std::exception & ex)
	{
		printer->printError(ex.what());
	}
}

const std::vector<std::unique_ptr<Layer>>& NeuralNetwork::getStructure() const
{
	return layers;
}

void NeuralNetwork::compile()
{
	try
	{
		printer->print("Before populating neurons:");
		populateLayers();
		printer->print("Before connecting layers:");
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

void NeuralNetwork::connectLayers()
{
	if (layers.size() < 1) throw std::exception{ "no layers to connect" };
	for (unsigned int i = 1; i < layers.size(); i++)
	{
		layers[i]->connect(*layers[i - 1]);
		//ConnectingEngine(*(layers[i]), *(layers[i + 1])).run();
	}
}

void NeuralNetwork::populateLayers()
{
	if (layers.size() < 1) throw std::exception{ "no layers to populate" };
	layers[0]->populateNeurons();
	for (unsigned int i = 1; i < layers.size(); i++)
		layers[i]->populateNeurons(*(layers[i - 1]));
}
