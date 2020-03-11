#include "NeuralNetwork.h"
#include "ConnectingEngine.h"
#include <time.h>
#include <stdlib.h>
#include <memory>
#include <iostream>

constexpr char RED[] = "\033[31m";
constexpr char RESET[] = "\033[0m";

NeuralNetwork::NeuralNetwork(bool printEnabled)
	: printEnabled{printEnabled}
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
		layers.push_back(std::make_unique<Layer>(layer)); //has to be like this because, cant transform to make_unique; this doesnt work: std::unique_ptr<Layer> newLayer = std::unique_ptr<Layer>(layer);
	}
	catch (std::exception ex)
	{
		printError(ex.what());
	}
}

void NeuralNetwork::compile()
{
	try
	{
		print("Before populating neurons:");
		populateLayers();
		print("Before connecting layers:");
		connectLayers();
		print("After connecting layers:");
	}
	catch (std::exception ex)
	{
		printError(ex.what());
	}
	catch (...)
	{
		printError("Unknown error.");
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

void NeuralNetwork::print(std::string description)
{
	if(description != "")
		std::cout << description << std::endl;
	if(printEnabled)
		for (auto& layer : layers) {
			layer->print();
		}
}

void NeuralNetwork::printError(std::string error)
{
	std::cerr << RED << "ERROR: {" << error << "}" << RESET << std::endl;
}
