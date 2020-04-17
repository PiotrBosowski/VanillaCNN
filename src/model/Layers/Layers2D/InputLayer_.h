//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INPUTLAYER__H
#define VANILLACNN_CLION_INPUTLAYER__H

#include "../Layer.h"
#include "Layer2D.h"
#include <vector>
#include <string>

class InputLayer_ : public Layer2D
{
public:
    InputLayer_(int inputHeight, int inputWidth);

    void connect() override;

    void populate() override;

    std::string getSummary() override;
};



#endif //VANILLACNN_CLION_INPUTLAYER__H
