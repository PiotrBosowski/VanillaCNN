//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURALNETWORK_H
#define VANILLACNN_CLION_NEURALNETWORK_H

//TODO add README.md

#include <memory>
#include <vector>
#include "Exceptions/Exceptions.h"
#include "Layers/LayerPrototypes/PrototypeLayer.h"
#include "Layers/Layer.h"
#include "OutputSource.h"

class NeuralNetwork : public OutputSource
{
public:
    explicit NeuralNetwork(bool printingEnabled = true);

private:
    std::vector<std::unique_ptr<Layer>> layers;
    std::vector<std::shared_ptr<PrototypeLayer>> prototypeLayers;

public:
    void addLayer(PrototypeLayer* newLayer);
    void compile();

    [[nodiscard]] std::string getOutput() const override;

private:
    void createLayersFromPrototypes();

    void populateLayers();

    void connectLayers();
};



#endif //VANILLACNN_CLION_NEURALNETWORK_H
