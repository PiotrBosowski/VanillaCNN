//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSNEURON_H
#define VANILLACNN_CLION_WEIGHTLESSNEURON_H

#include "Neuron.h"

class WeightlessNeuron :
        public Neuron
{
public:
    void acceptConnection(std::unique_ptr<Connection> connection) override;

    void calculateValue() override;
};



#endif //VANILLACNN_CLION_WEIGHTLESSNEURON_H
