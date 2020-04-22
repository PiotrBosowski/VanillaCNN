//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H


#include <Weights/Weight.h>
#include "Connection.h"

class InternallyWeightedConnection : public Connection
{
public:
    explicit InternallyWeightedConnection(Neuron& connNeuron);
protected:
    Weight connectionWeight;
public:
    Weight &getWeight() override;
};




#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
