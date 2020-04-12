//
// Created by piotr on 20/04/11.
//

#include "ContainersConnectingError.h"
#include "../exceptions/Exceptions.h"
#include <exception>

ContainersConnectingError::ContainersConnectingError()
{
}

void ContainersConnectingError::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Layer& sourceLayer, Layer& previousLayer)
{
    throw ConnectingException{ "cannot connect containers here" };
}
