//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
#include "Matrix.h"
#include "../../Neurons/Weights.h"
#include "../IInternallyWeightedContainer.h"


class InternallyWeightedMatrix : public Matrix, public IInternallyWeightedContainer
{
public:
    InternallyWeightedMatrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth);

private:
    int weightsHeight;
    int weightsWidth;
    std::unique_ptr<Weights> weights;
public:
    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                 Container &precedingContainer) override;

    double& getWeight(int neuronIndex) override;
};



#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
