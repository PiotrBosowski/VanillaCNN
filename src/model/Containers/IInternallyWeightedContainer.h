//
// Created by piotr on 20/04/17.
//

#ifndef VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H
#define VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H


struct IInternallyWeightedContainer {
    virtual Weight& getWeight(int neuronIndex) = 0;
    virtual int getWeightsHeight() = 0;
    virtual int getWeightsWidth() = 0;
};


#endif //VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H
