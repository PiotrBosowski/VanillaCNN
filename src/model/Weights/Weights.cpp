//
// Created by piotr on 20/04/11.
//

#include <cstdlib>
#include "Weights.h"
#include "Exceptions/Exceptions.h"

Weights::Weights(int height, int width)
{
    for (int i = 0; i < height * width; ++i) {
        weights.push_back((double)rand()/(double)RAND_MAX);
    }
}

Weights::Weights(int length)
{
    for (int i = 0; i < length; ++i) {
        weights.push_back((double)rand()/(double)RAND_MAX);
    }
}

double &Weights::getWeight(int index) {
    if(index < weights.size())
        return weights[index];
    throw WeightsOutOfRangeError("Error trying to access weight beyond the vector");
}
