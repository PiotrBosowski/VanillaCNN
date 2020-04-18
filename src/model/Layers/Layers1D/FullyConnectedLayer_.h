//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_FULLYCONNECTEDLAYER__H
#define VANILLACNN_CLION_FULLYCONNECTEDLAYER__H


#include <string>
#include "../Layer.h"
#include "Layer1D.h"

class FullyConnectedLayer_ : public Layer1D
{
public:
    FullyConnectedLayer_(Layer * previousLayer, int numberOfNeurons);

    void connect() override;

    void populate() override;

    std::stringstream getSummary() override;

    std::string getName() override;
};



#endif //VANILLACNN_CLION_FULLYCONNECTEDLAYER__H
