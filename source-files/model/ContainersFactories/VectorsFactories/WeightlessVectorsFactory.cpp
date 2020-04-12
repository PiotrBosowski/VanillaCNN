//
// Created by piotr on 20/04/11.
//

#include "WeightlessVectorsFactory.h"
#include "../../Containers/Vectors/Vector.h"

WeightlessVectorsFactory::WeightlessVectorsFactory(int numberOfNeurons)
        : numberOfNeurons{ numberOfNeurons }
{
}

std::unique_ptr<Container>
WeightlessVectorsFactory::createContainer(ContainersConnectingStrategy &containersConnectingStrategy,
                                          NeuronsFactory &neuronsFactory,
                                          NeuronsConnectingStrategy &neuronsConnectingStrategy) {
    return std::unique_ptr<Container>();
}
