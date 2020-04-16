//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_FULLYCONNECTEDLAYER_H
#define VANILLACNN_CLION_FULLYCONNECTEDLAYER_H


#include "PrototypeLayer.h"

class FullyConnectedLayer : public PrototypeLayer
{
public:
    FullyConnectedLayer(int numberOfNeurons);
    std::unique_ptr<Layer> embodyLayer(Layer* previousLayer) override;

private:
    int numberOfNeurons;
};



#endif //VANILLACNN_CLION_FULLYCONNECTEDLAYER_H
