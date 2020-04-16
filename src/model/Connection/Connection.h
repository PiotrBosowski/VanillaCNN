//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONNECTION_H
#define VANILLACNN_CLION_CONNECTION_H


class Neuron;

class Connection
{
public:
    explicit Connection(Neuron &connectedNeuron);

protected:
    Neuron& connectedNeuron;
public:
    Neuron& getNeuron();
};




#endif //VANILLACNN_CLION_CONNECTION_H
