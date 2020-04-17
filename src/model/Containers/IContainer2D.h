//
// Created by piotr on 20/04/17.
//

#ifndef VANILLACNN_CLION_ICONTAINER2D_H
#define VANILLACNN_CLION_ICONTAINER2D_H

class Neuron;

class IContainer2D {
    virtual Neuron& getNeuron(unsigned int height, unsigned int width) = 0;

    virtual unsigned getHeightFromIndex(unsigned neuronIndex) = 0;
    virtual unsigned getWidthFromIndex(unsigned neuronIndex) = 0;
};


#endif //VANILLACNN_CLION_ICONTAINER2D_H
