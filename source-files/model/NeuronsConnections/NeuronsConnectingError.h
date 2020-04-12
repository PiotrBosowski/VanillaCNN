//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSCONNECTINGERROR_H
#define VANILLACNN_CLION_NEURONSCONNECTINGERROR_H

#include "NeuronsConnectingStrategy.h"
class NeuronsConnectingError : public NeuronsConnectingStrategy
{
    void connect(Container& sourceContainer, Container& previousContainer) override;
};




#endif //VANILLACNN_CLION_NEURONSCONNECTINGERROR_H
