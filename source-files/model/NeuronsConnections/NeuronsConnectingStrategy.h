//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H
#define VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H


class Container;

class NeuronsConnectingStrategy
{
public:
    virtual void connect(Container& sourceContainer, Container& previousContainer) = 0;
};



#endif //VANILLACNN_CLION_NEURONSCONNECTINGSTRATEGY_H
