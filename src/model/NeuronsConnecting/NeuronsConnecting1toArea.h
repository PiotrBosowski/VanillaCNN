//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSCONNECTING1TOAREA_H
#define VANILLACNN_CLION_NEURONSCONNECTING1TOAREA_H


#include "NeuronsConnectingStrategy.h"
#include "Containers/Container.h"

class NeuronsConnecting1toArea : public NeuronsConnectingStrategy
{
public:
    NeuronsConnecting1toArea(int areaHeight, int areaWidth, int verticalStride, int horizontalStride);
    std::vector<Neuron *> proposeSingleNeuronConnections(unsigned neuronIndex, Container &source, Container &preceding) override;

private:
    int areaHeight, areaWidth;
    int verticalStride, horizontalStride;
};




#endif //VANILLACNN_CLION_NEURONSCONNECTING1TOAREA_H
