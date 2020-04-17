//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_LAYER_H
#define VANILLACNN_CLION_LAYER_H

#include "../Neurons/Neuron.h"
#include <memory>
#include "../Containers/Container.h"
#include "../ContainersConnectingStrategy/ContainersConnectingStrategy.h"
#include "../ContainersFactories/ContainersFactory.h"
#include "../NeuronsConnections/NeuronsConnectingStrategy.h"
#include "../Docker/Docker.h"
#include "IConnectible.h"
#include "IPrintable.h"
#include "IPopulatible.h"
#include <string>

class Layer : public IPopulatible, public IConnectible, public IPrintable
{
public:
    Layer(Layer* previousLayer,
          int numberOfContainers);

protected:
    int numberOfContainers;
    Layer *previousLayer;
    std::unique_ptr<Docker> docker;
public:
    [[nodiscard]] const std::unique_ptr<Docker> &getDocker() const;

public:
    int getNumberOfContainers();
};


#endif //VANILLACNN_CLION_LAYER_H
