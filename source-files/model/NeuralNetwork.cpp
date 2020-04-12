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
    if (layer != nullptr)
        prototypeLayers.push_back(std::unique_ptr<PrototypeLayer>(layer));
    else throw LayerCreatingException("cant create layer from nullptr");
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

void NeuralNetwork::createLayersFromPrototypes()
{
    if (prototypeLayers.empty()) throw NetworkCreatingException("cannot create empty network");
    layers.reserve(15);
    layers.push_back(std::move(prototypeLayers[0]->embodyLayer(nullptr)));
    try{
        for (int i = 1; i < prototypeLayers.size(); i++)
        {
            printer->print("Right before layer creation:");
            layers.push_back(std::move(prototypeLayers[i]->embodyLayer(layers[i - 1].get())));
        }
    }
    catch(...)
    {
        std::cout << "error occurred" << std::endl;
    }
}

std::string NeuralNetwork::getOutput() const {
    std::string result;
    for (auto& layer : layers)
        result+=layer->getSummary();
    return result;
}
