#include "NeuralNetwork.h"
#include "ConnectingEngine.h"
#include <time.h>
#include <stdlib.h>
#include <memory>
#include <iostream>

NeuralNetwork::NeuralNetwork()
{
	srand((unsigned int)time(NULL));
}

void NeuralNetwork::addLayer(Layer * layer)
{
	try
	{
		if (!dynamic_cast<Layer*>(layer)) //checks if null also
			throw std::exception("ERROR: Bad Layer initialization, nothing was added.");
		layers.push_back(std::move(std::unique_ptr<Layer>(layer))); //has to be like this because, cant transform to make_unique; this doesnt work: std::unique_ptr<Layer> newLayer = std::unique_ptr<Layer>(layer);
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

void NeuralNetwork::connectLayers(){
	for (unsigned int i = 0; i < layers.size() - 1; i++)
	{
		ConnectingEngine(*(layers[i]), *(layers[i + 1])).run();
	}
}

void NeuralNetwork::compile()
{
	try 
	{
		print();
		populateLayers();
		print();
		connectLayers();
		print();
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "ERROR: Unknown error." << std::endl;
	}
}

void NeuralNetwork::populateLayers()
{
	if (layers.size() < 1) throw std::exception{ "no layers included" };
	layers[0]->populateNeurons();
	for (unsigned int i = 1; i < layers.size(); i++)
		layers[i]->populateNeurons(*(layers[i - 1]));
}

void NeuralNetwork::print()
{
	for (auto& layer : layers) {
		layer->print();
	}
}