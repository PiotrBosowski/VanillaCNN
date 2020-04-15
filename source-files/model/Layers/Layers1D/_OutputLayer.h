//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__OUTPUTLAYER_H
#define VANILLACNN_CLION__OUTPUTLAYER_H


#include "../Layer.h"
#include "Layer1D.h"

class _OutputLayer : public Layer1D
{
public:
    _OutputLayer(Layer* previousLayer, int numberOfNeurons);

public:
    std::string getSummary() override;

    void connect() override;

    void populate() override;
};


#endif //VANILLACNN_CLION__OUTPUTLAYER_H
