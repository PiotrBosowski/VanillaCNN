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
        populateLayers();
        connectLayers();
        printer->print("");
    }
    catch (const std::exception & ex)
    {
        printer->printError(ex.what());
    }
}

void NeuralNetwork::createLayersFromPrototypes()
{
    if (prototypeLayers.empty()) throw NetworkCreatingException("cannot create empty network");
    layers.push_back(std::move(prototypeLayers[0]->embodyLayer(nullptr)));
    try{
        for (int i = 1; i < prototypeLayers.size(); i++)
        {
            layers.push_back(prototypeLayers[i]->embodyLayer(layers[i - 1].get()));
        }
    }
    catch(...)
    {
        std::cout << "error occurred" << std::endl;
    }
}

void NeuralNetwork::populateLayers() {
    for(auto& layer : layers)
        layer->populate();
}

void NeuralNetwork::connectLayers() {
    for (int i = 1; i < layers.size(); ++i){
        layers[i]->connect();
    }
}

std::string NeuralNetwork::getOutput() const {
    if(printingEnabled)
    {
        std::stringstream result;
        result << "Neural network: " << this
        << ", printer: " << &this->printer
        << ", printingEnabled: " << printingEnabled << std::endl
        << "Prototype layers: [" << std::endl;
        for (auto& protLayer : prototypeLayers)
            result << "\t" << protLayer->getSummary().str() << "\n";
        result << "]" << std::endl
        << "Real layers: [" << std::endl;
        for (auto& layer : layers)
            result << "\t" << layer->getSummary().str() << "\n";
        result << "]" << std::endl;
        return result.str();
    }
    else return "";
}