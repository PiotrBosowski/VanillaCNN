//
// Created by piotr on 20/04/11.
//

#include "Container.h"

Container::Container()
{
}

void Container::connect(NeuronsConnectingStrategy& neuronsConnectingStrategy, Container& preceedingContainer)
{
    neuronsConnectingStrategy.connect(*this, preceedingContainer);
}
