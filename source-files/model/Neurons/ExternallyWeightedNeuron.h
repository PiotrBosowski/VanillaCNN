//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURON_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURON_H


#include "Neuron.h"
class ExternallyWeightedNeuron :
        public Neuron
{
public:
    void connect(Neuron &preceding) override;
    void connect(Neuron& preceding, double& weightReference);

    void calculateValue() override;

};



#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDNEURON_H
