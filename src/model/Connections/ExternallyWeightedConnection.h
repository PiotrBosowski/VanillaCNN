//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H


#include "Connection.h"

class ExternallyWeightedConnection : public Connection
{
protected:
    Weight& connectionWeight;
public:
    ExternallyWeightedConnection(Neuron &connectedNeuron, Weight &connectionWeight);

    Weight &getWeight() override;
};


#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
