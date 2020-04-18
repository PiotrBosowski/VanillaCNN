//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_LAYER2D_H
#define VANILLACNN_CLION_LAYER2D_H


#include "../Layer.h"
#include "../../Containers/Matrices/Matrix.h"
#include <memory>

class Layer2D : public Layer
{
public:
    Layer2D(Layer* previousLayer,
            int numberOfContainers,
            int matrixHeight,
            int matrixWidth);

protected:
    int matrixHeight;
    int matrixWidth;

public:
    int getMatrixHeight();
    int getMatrixWidth();

    std::stringstream getSummary() override;

    std::string getName() override;
};


#endif //VANILLACNN_CLION_LAYER2D_H
