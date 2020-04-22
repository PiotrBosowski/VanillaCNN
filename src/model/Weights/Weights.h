//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTS_H
#define VANILLACNN_CLION_WEIGHTS_H

#include <vector>
#include "Weight.h"

class Weights
{
public:
    explicit Weights(int height, int width);
    explicit Weights(int length);
protected:
    std::vector<Weight> weights;
public:
    Weight& getWeight(int index);
    int size();
};


#endif //VANILLACNN_CLION_WEIGHTS_H
