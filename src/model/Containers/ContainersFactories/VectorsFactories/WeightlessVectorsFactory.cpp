//
// Created by piotr on 20/04/11.
//

#include "WeightlessVectorsFactory.h"
#include "../../Vectors/Vector.h"
#include "../../Vectors/WeightlessVector.h"

WeightlessVectorsFactory::WeightlessVectorsFactory(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
}

std::unique_ptr<Container>
WeightlessVectorsFactory::createContainer() {

    return std::make_unique<WeightlessVector>(numberOfNeurons);
}
