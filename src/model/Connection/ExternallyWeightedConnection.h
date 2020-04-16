//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
#define VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H


#include "Connection.h"
#include "Weight.h"

class UnweightedConnection : public Connection
{
protected:
    Weight& connectionWeight;
};


#endif //VANILLACNN_CLION_EXTERNALLYWEIGHTEDCONNECTION_H
