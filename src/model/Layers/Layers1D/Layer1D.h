//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_LAYER1D_H
#define VANILLACNN_CLION_LAYER1D_H

#include <vector>
#include <iostream>
#include <memory>

#include "Layers/Layer.h"
#include "Containers/Matrices/Matrix.h"
#include "Containers/Vectors/Vector.h"
#include "Layer1D.h"

class Layer1D : public Layer
{
public:
    Layer1D(Layer* previousLayer,
            int numberOfContainers,
            int vectorLength);

    std::stringstream getSummary() override;

    std::string getName() override;

protected:
    int numberOfNeurons;
};


#endif //VANILLACNN_CLION_LAYER1D_H
