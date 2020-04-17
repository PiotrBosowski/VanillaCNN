//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSMATRIX_H
#define VANILLACNN_CLION_WEIGHTLESSMATRIX_H


#include "Matrix.h"
#include "../IWeightlessContainer.h"

class WeightlessMatrix : public Matrix, public IWeightlessContainer
{
public:
    WeightlessMatrix(int matrixHeight, int matrixWidth);

    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory& connectionsFactory, Container &precedingContainer) override;
};




#endif //VANILLACNN_CLION_WEIGHTLESSMATRIX_H
