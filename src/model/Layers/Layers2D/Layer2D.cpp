//
// Created by piotr on 20/04/11.
//

#include <iostream>
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

int Layer2D::getMatrixHeight()
{
    return matrixHeight;
}

int Layer2D::getMatrixWidth()
{
    return matrixWidth;
}

std::stringstream Layer2D::getSummary() {
    std::stringstream ss;
    ss << Layer2D::getName() << "{ matrixHeight: " << matrixHeight << ", matrixWidth: " << matrixWidth << ", "<< Layer::getSummary().str() << " }";
    return ss;
}

std::string Layer2D::getName() {
    return "Layer2D";
}