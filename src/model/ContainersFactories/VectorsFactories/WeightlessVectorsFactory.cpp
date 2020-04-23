//
// Created by piotr on 20/04/11.
//

#include <Exceptions/Exceptions.h>
#include "WeightlessVectorsFactory.h"
#include "Containers/Vectors/Vector.h"
#include "Containers/Vectors/WeightlessVector.h"

WeightlessVectorsFactory::WeightlessVectorsFactory(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
    if(numberOfNeurons < 1) throw ContainersCreatingException("cannot create weightless vectors factory with negative number of neurons");
}

std::unique_ptr<Container>
WeightlessVectorsFactory::createContainer() {

    return std::make_unique<WeightlessVector>(numberOfNeurons);
}
