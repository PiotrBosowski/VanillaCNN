//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_LAYER_H
#define VANILLACNN_CLION_LAYER_H

#include "../Neurons/Neuron.h"
#include <memory>
#include "../Containers/Container.h"
#include "../ContainersConnectingStrategy/ContainersConnectingStrategy.h"
#include "../NeuronsFactories/NeuronsFactory.h"
#include "../ContainersFactories/ContainersFactory.h"
#include "../NeuronsConnections/NeuronsConnectingStrategy.h"
#include "../Containers/Docker.h"
#include <string>

class Layer
{
public:
    Layer(Layer* previousLayer, int numberOfContainers);

protected:
    int numberOfContainers;
    Layer *previousLayer;
    std::unique_ptr<Docker> docker;

public:
    void setPreviousLayer(std::shared_ptr<Layer> previousLayer);
    virtual int getNumberOfContainers();
    void connectToPreceding();
    virtual std::string getSummary();
    std::vector<std::unique_ptr<Container>>& getContainers();
};


#endif //VANILLACNN_CLION_LAYER_H
