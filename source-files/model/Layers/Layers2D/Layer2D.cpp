//
// Created by piotr on 20/04/11.
//

#include <iostream>
#include <vector>
#include <string>
#include "Layer2D.h"


Layer2D::Layer2D(Layer* previousLayer,
                int numberOfContainers,
                 int matrixHeight,
                 int matrixWidth)
        : Layer{ previousLayer, numberOfContainers},
          matrixHeight{ matrixHeight },
          matrixWidth{ matrixWidth }
{
}

std::string Layer2D::getSummary()
{
    std::string result = Layer::getSummary() + "\tLayer2D: numberOfMatrices(" + std::to_string(numberOfContainers)
                         + "), matrixHeight(" + std::to_string(matrixHeight) + "), matrixWidth(" + std::to_string(matrixWidth) + ")\n";
    return result;
}

int Layer2D::getMatrixHeight()
{
    return matrixHeight;
}

int Layer2D::getMatrixWidth()
{
    return matrixWidth;
}
