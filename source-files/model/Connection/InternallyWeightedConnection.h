//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H


#include "Connection.h"
#include "Weight.h"

class InternallyWeightedConnection : public Connection
{
protected:
    Weight connectionWeight;
};




#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDCONNECTION_H
