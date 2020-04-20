//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_PROTOTYPELAYER_H
#define VANILLACNN_CLION_PROTOTYPELAYER_H

#include <memory>
#include "Layers/Layer.h"

class PrototypeLayer : public IPrintable
{
public:
    virtual std::unique_ptr<Layer> embodyLayer(Layer * previousLayer) = 0;
};



#endif //VANILLACNN_CLION_PROTOTYPELAYER_H
