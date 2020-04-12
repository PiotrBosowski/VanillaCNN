//
// Created by piotr on 20/04/11.
//

#include "../../NeuronsFactories/NeuronsFactory.h"
#include "Vector.h"
#include "WeightlessVector.h"

WeightlessVector::WeightlessVector(NeuronsFactory &neuronFactory, int vectorHeight)
: Vector(neuronFactory, vectorHeight) {}
