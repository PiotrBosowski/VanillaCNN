//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTINGERROR_H
#define VANILLACNN_CLION_CONTAINERSCONNECTINGERROR_H


#include "ContainersConnectingStrategy.h"
class ContainersConnectingError : public ContainersConnectingStrategy
{
public:
    ContainersConnectingError();
    void connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer) override;

};



#endif //VANILLACNN_CLION_CONTAINERSCONNECTINGERROR_H
