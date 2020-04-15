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
    Matrix(NeuronsFactory& neuronsFactory, int matrixHeight, int matrixWidth);

protected:
    int matrixHeight;
    int matrixWidth;

public:
    [[nodiscard]] int getMatrixHeight() const;
    [[nodiscard]] int getMatrixWidth() const;
    Neuron& getNeuron(unsigned int row, unsigned int column);
};


#endif //VANILLACNN_CLION_MATRIX_H
