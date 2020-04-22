//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSVECTOR_H
#define VANILLACNN_CLION_WEIGHTLESSVECTOR_H

#include "Vector.h"
#include "Containers/IWeightlessContainer.h"

class WeightlessVector : public Vector, public IWeightlessContainer
{
public:
    explicit WeightlessVector(int vectorHeight);

    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                 Container &preceedingContainer) override;
};

#endif //VANILLACNN_CLION_WEIGHTLESSVECTOR_H
