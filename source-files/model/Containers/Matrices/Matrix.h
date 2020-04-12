//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_MATRIX_H
#define VANILLACNN_CLION_MATRIX_H

#include <vector>
#include "../../Neurons/Neuron.h"
#include "../Container.h"

class Matrix : public Container
{
public:
    Matrix(int matrixHeight, int matrixWidth, NeuronsFactory& neuronsFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy);

private:
    int matrixHeight;
    int matrixWidth;
    std::vector<std::unique_ptr<Neuron>> table;

public:
    int getMatrixHeight();
    int getMatrixWidth();
    Neuron& getNeuron(unsigned int index) override;
    Neuron& getNeuron(unsigned int row, unsigned int column);
    unsigned int getNumberOfNeurons() override;
};


#endif //VANILLACNN_CLION_MATRIX_H
