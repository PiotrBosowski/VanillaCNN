//
// Created by piotr on 20/04/17.
//

#ifndef VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H
#define VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H


struct IInternallyWeightedContainer {
    virtual double& getWeight(int neuronIndex) = 0;
};


#endif //VANILLACNN_CLION_IINTERNALLYWEIGHTEDCONTAINER_H
