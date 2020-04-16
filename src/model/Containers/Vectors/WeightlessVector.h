//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSVECTOR_H
#define VANILLACNN_CLION_WEIGHTLESSVECTOR_H

#include "Vector.h"
class WeightlessVector : public Vector
{
public:
    WeightlessVector(NeuronsFactory &neuronFactory, int vectorHeight);

    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, Container &preceedingContainer) override;
};

#endif //VANILLACNN_CLION_WEIGHTLESSVECTOR_H
