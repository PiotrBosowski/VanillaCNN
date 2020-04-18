//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_OUTPUTLAYER__H
#define VANILLACNN_CLION_OUTPUTLAYER__H


#include "../Layer.h"
#include "Layer1D.h"

class OutputLayer_ : public Layer1D
{
public:
    OutputLayer_(Layer* previousLayer, int numberOfNeurons);

public:
    std::stringstream getSummary() override;

    void connect() override;

    void populate() override;

    std::string getName() override;
};


#endif //VANILLACNN_CLION_OUTPUTLAYER__H
