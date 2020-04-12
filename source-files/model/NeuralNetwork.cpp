//
// Created by piotr on 20/04/11.
//

#include "NeuralNetwork.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>


NeuralNetwork::NeuralNetwork(bool printingEnabled)
        : OutputSource{ printingEnabled }
{
    srand((unsigned int)time(NULL));
}

void NeuralNetwork::addLayer(PrototypeLayer* layer)
{
    if (layer == nullptr)
        prototypeLayers.push_back(std::unique_ptr<PrototypeLayer>(layer));
}

void NeuralNetwork::compile()
{
    try
    {
        createLayersFromPrototypes();
        printer->print("Finished Network:");
    }
    catch (const std::exception & ex)
    {
        printer->printError(ex.what());
    }
}

const std::vector<std::shared_ptr<Layer>>& NeuralNetwork::getOutput() const
{
    return std::vector<std::shared_ptr<Layer>>();
    // TODO: insert return statement here
}

void NeuralNetwork::createLayersFromPrototypes()
{
    if (prototypeLayers.size() < 1) throw LayerCreatingException("cannot create empty network");
    layers.push_back(std::move(prototypeLayers[0]->embodyLayer(nullptr)));
    for (int i = 1; i < prototypeLayers.size(); i++)
    {
        layers.push_back(std::move(prototypeLayers[i]->embodyLayer(layers[i - 1].get())));
    }
}
