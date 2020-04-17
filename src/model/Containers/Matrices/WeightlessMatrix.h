//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSMATRIX_H
#define VANILLACNN_CLION_WEIGHTLESSMATRIX_H


#include "Matrix.h"
class WeightlessMatrix : public Matrix
{
public:
    WeightlessMatrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth);

    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory& connectionsFactory, Container &preceedingContainer) override;
};




#endif //VANILLACNN_CLION_WEIGHTLESSMATRIX_H
