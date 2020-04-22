//
// Created by piotr on 20/04/16.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSCONNECTION_H
#define VANILLACNN_CLION_WEIGHTLESSCONNECTION_H


#include "Connection.h"

class WeightlessConnection : public Connection {

public:
    explicit WeightlessConnection(Neuron &connectedNeuron);
    Weight &getWeight() override;
};



#endif //VANILLACNN_CLION_WEIGHTLESSCONNECTION_H
