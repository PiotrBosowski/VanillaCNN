//
// Created by piotr on 20/04/11.
//

#include "../../NeuronsFactories/NeuronsFactory.h"
#include "Vector.h"
#include "WeightlessVector.h"
#include "../../Neurons/WeightlessNeuron.h"
#include "../../exceptions/Exceptions.h"

WeightlessVector::WeightlessVector(NeuronsFactory &neuronFactory, int vectorHeight)
: Vector(neuronFactory, vectorHeight) {}

void WeightlessVector::connect(NeuronsConnectingStrategy &neuronsConnectingStrategy, Container &preceedingContainer) {
    try {
        for (auto & neuron : neurons) {
            auto connections = neuronsConnectingStrategy.proposeConnections(*neuron, &preceedingContainer);
            for(auto& conn : connections)
            {
                dynamic_cast<WeightlessNeuron*>(neuron.get())->connect(*conn);
            }
        }
    }
    catch (const std::bad_cast&) {
        throw NeuronsConnectingException("Weightless Vector can only be used with Weightless Neurons");
    }
}
