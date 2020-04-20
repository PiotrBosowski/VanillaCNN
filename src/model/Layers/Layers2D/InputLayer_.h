//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INPUTLAYER__H
#define VANILLACNN_CLION_INPUTLAYER__H

#include <vector>
#include <string>

#include "Layers/Layer.h"
#include "Layer2D.h"

class InputLayer_ : public Layer2D
{
public:
    InputLayer_(int inputHeight, int inputWidth);

    void connect() override;

    void populate() override;

    std::stringstream getSummary() override;

    std::string getName() override;
};



#endif //VANILLACNN_CLION_INPUTLAYER__H
