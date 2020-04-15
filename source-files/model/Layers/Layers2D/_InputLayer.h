//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__INPUTLAYER_H
#define VANILLACNN_CLION__INPUTLAYER_H

#include "../Layer.h"
#include "Layer2D.h"
#include <vector>
#include <string>

class _InputLayer : public Layer2D
{
public:
    _InputLayer(int inputHeight, int inputWidth);
    std::string getSummary() override;

    void connect() override;

    void populate() override;
};


#endif //VANILLACNN_CLION__INPUTLAYER_H
