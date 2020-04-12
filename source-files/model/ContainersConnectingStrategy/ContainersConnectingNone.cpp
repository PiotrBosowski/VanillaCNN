//
// Created by piotr on 20/04/11.
//

#include "ContainersConnectingNone.h"
#include "../exceptions/Exceptions.h"
#include <exception>

ContainersConnectingNone::ContainersConnectingNone()
{
}

void ContainersConnectingNone::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Docker& source, Docker* preceding)
{
    //throw ConnectingException{ "cannot connect containers here" };
    goto wypierdalaj;

    wypierdalaj: return;
}
