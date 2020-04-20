//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_LAYER_H
#define VANILLACNN_CLION_LAYER_H

#include <memory>
#include <string>
#include <ostream>

#include "Neurons/Neuron.h"
#include "Containers/Container.h"
#include "Docker/Docker.h"
#include "IConnectible.h"
#include "IPrintable.h"
#include "IPopulatible.h"

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
    [[nodiscard]] int getNumberOfContainers() const;

    std::stringstream getSummary() override;

    std::string getName() override;
};


#endif //VANILLACNN_CLION_LAYER_H
