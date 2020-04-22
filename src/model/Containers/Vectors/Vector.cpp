//
// Created by piotr on 20/04/11.
//

#include <Exceptions/Exceptions.h>
#include "Vector.h"

Vector::Vector(int vectorHeight)
          : Container (vectorHeight), vectorHeight{ vectorHeight }
{
    if (vectorHeight < 0) throw ContainersCreatingException("cannot create vector with negative number of neurons");
}
