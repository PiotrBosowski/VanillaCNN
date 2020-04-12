//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INPUTLAYER_H
#define VANILLACNN_CLION_INPUTLAYER_H


#include "PrototypeLayer.h"

class InputLayer : public PrototypeLayer
{
public:
    InputLayer(int inputHeight, int inputWidth);
    std::unique_ptr<Layer> embodyLayer(Layer* previousLayer) override;
private:
    int inputHeight;
    int inputWidth;
};



#endif //VANILLACNN_CLION_INPUTLAYER_H
