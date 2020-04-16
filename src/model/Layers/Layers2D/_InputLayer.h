//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__INPUTLAYER_H
#define VANILLACNN_CLION__INPUTLAYER_H

#include "../Layer.h"
#include "Layer2D.h"
#include <vector>
#include <string>

//TODO change names that are reserved
class _InputLayer : public Layer2D
{
public:
    _InputLayer(int inputHeight, int inputWidth);

    void connect() override;

    void populate() override;

    std::string getSummary() override;
};



#endif //VANILLACNN_CLION__INPUTLAYER_H
