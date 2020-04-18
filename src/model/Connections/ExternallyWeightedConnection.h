//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H


#include "Connection.h"

class ExternallyWeightedConnection : public Connection
{
protected:
    double& connectionWeight;
public:
    ExternallyWeightedConnection(Neuron &connectedNeuron, double &connectionWeight);
};


#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
