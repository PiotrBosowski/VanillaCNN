//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_FULLYCONNECTEDLAYER_H
#define VANILLACNN_CLION_FULLYCONNECTEDLAYER_H


#include "PrototypeLayer.h"

class FullyConnectedLayer : public PrototypeLayer
{
public:
    explicit FullyConnectedLayer(int numberOfNeurons);
    std::unique_ptr<Layer> embodyLayer(Layer* previousLayer) override;

    std::string getName() override;

    std::stringstream getSummary() override;

private:
    int numberOfNeurons;
};



#endif //VANILLACNN_CLION_FULLYCONNECTEDLAYER_H
