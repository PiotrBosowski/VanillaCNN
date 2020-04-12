//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURALNETWORK_H
#define VANILLACNN_CLION_NEURALNETWORK_H


#include <memory>
#include <vector>
#include "exceptions/Exceptions.h"
#include "Layers/LayerPrototypes/PrototypeLayer.h"
#include "Layers/Layer.h"
#include "../output/OutputSource.h"

class NeuralNetwork : public OutputSource
{
public:
    NeuralNetwork(bool printingEnabled = true);

private:
    std::vector<std::unique_ptr<Layer>> layers;
    std::vector<std::shared_ptr<PrototypeLayer>> prototypeLayers;

public:
    void addLayer(PrototypeLayer* newLayer);
    void compile();
    const std::vector<std::shared_ptr<Layer>>& getOutput() const override;

private:
    void createLayersFromPrototypes();
};



#endif //VANILLACNN_CLION_NEURALNETWORK_H
