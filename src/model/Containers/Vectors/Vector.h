//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_VECTOR_H
#define VANILLACNN_CLION_VECTOR_H

#include <vector>
#include <memory>
#include "Containers/Container.h"
#include "Neurons/Neuron.h"

class Vector : public Container
{
public:
    explicit Vector(int vectorHeight);

private:
    int vectorHeight;
};



#endif //VANILLACNN_CLION_VECTOR_H
