//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
#include "Matrix.h"
#include "Weights/Weights.h"
#include "Containers/IInternallyWeightedContainer.h"


class InternallyWeightedMatrix : public Matrix, public IInternallyWeightedContainer
{
public:
    InternallyWeightedMatrix(int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth);

private:
    int weightsHeight;
    int weightsWidth;
    std::unique_ptr<Weights> weights;
public:
    void connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, ConnectionsFactory &connectionsFactory,
                 Container &precedingContainer) override;

    Weight& getWeight(int neuronIndex) override;

    int getWeightsHeight() override;

    int getWeightsWidth() override;
};



#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
