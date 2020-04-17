//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H


#include "Connection.h"

class InternallyWeightedConnection : public Connection
{
public:
    explicit InternallyWeightedConnection(Neuron& connNeuron);
protected:
    double connectionWeight;
};




#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
