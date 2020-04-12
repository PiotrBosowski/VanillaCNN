//
// Created by piotr on 20/04/11.
//

#include "ContainersConnectingError.h"
#include <exception>

ContainersConnectingError::ContainersConnectingError()
{
}

void ContainersConnectingError::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer)
{
    throw std::exception{ "cannot connect containers here" };
}
