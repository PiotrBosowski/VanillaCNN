//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_MATRIX_H
#define VANILLACNN_CLION_MATRIX_H

#include <vector>
#include "../../Neurons/Neuron.h"
#include "../Container.h"
#include "../IContainer2D.h"


class Matrix : public Container, public IContainer2D
{
public:
    Matrix(int matrixHeight, int matrixWidth);

public:
    unsigned int getHeightFromIndex(unsigned int neuronIndex) override;

    unsigned int getWidthFromIndex(unsigned int neuronIndex) override;

protected:
    int matrixHeight;
    int matrixWidth;

public:
    [[nodiscard]] int getMatrixHeight() const;
    [[nodiscard]] int getMatrixWidth() const;
    Neuron& getNeuron(unsigned int row, unsigned int column) override;
};

#endif //VANILLACNN_CLION_MATRIX_H
