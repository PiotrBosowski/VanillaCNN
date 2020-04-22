//
// Created by piotr on 20/04/11.
//

#include <cstdlib>
#include "Weights.h"
#include "Exceptions/Exceptions.h"

Weights::Weights(int height, int width)
 : weights(std::vector<Weight>(height * width))
{
    if(height < 0 || width < 0) throw WeightsOutOfRangeError();
}

Weights::Weights(int length)
: weights(std::vector<Weight>(length))
{
}

Weight& Weights::getWeight(int index) {
    if(index < weights.size())
        return weights[index];
    throw WeightsOutOfRangeError("Error trying to access weight beyond the vector");
}

int Weights::size() {
    return weights.size();
}

