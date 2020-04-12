//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_VECTOR_H
#define VANILLACNN_CLION_VECTOR_H


#include "../Container.h"
#include "../../NeuronsConnections/NeuronsConnectingStrategy.h"
#include <vector>
#include <memory>
#include "../../Neurons/Neuron.h"

class Vector : public Container
{
public:
    Vector(NeuronsFactory& neuronFactory, int vectorHeight);

private:
    int vectorHeight;
    std::vector<std::unique_ptr<Neuron>> row;

public:
    int getVectorHeight();
    Neuron& getNeuron(unsigned int index) override;
    unsigned int getNumberOfNeurons() override;
};



#endif //VANILLACNN_CLION_VECTOR_H
