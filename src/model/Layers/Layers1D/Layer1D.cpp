//
// Created by piotr on 20/04/11.
//


#include "Layer1D.h"

Layer1D::Layer1D(Layer* previousLayer,
                int numberOfContainers,
                 int numberOfNeurons)
        : Layer{ previousLayer, numberOfContainers},
          numberOfNeurons{numberOfNeurons}
{

}
