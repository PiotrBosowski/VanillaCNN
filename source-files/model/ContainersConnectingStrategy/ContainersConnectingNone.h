//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONTAINERSCONNECTINGNONE_H
#define VANILLACNN_CLION_CONTAINERSCONNECTINGNONE_H


#include "ContainersConnectingStrategy.h"
class ContainersConnectingNone : public ContainersConnectingStrategy
{
public:
    ContainersConnectingNone();
    void proposeConnections(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding) override;

};



#endif //VANILLACNN_CLION_CONTAINERSCONNECTINGNONE_H
