//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__FULLYCONNECTEDLAYER_H
#define VANILLACNN_CLION__FULLYCONNECTEDLAYER_H


#include <string>
#include "../Layer.h"
#include "Layer1D.h"

class _FullyConnectedLayer : public Layer1D
{
public:
    _FullyConnectedLayer(Layer * previousLayer, int numberOfNeurons);
    std::string getSummary() override;
};



#endif //VANILLACNN_CLION__FULLYCONNECTEDLAYER_H
