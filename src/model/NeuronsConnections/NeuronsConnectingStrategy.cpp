//
// Created by piotr on 20/04/16.
//

#include "NeuronsConnectingStrategy.h"

void NeuronsConnectingStrategy::moveToTheNextNeuron(int sourceHeight, int sourceWidth) {
    this->currentNeuronWidth++;
    if (this->currentNeuronWidth == sourceWidth) // if you reach the end of the row
    {
        this->currentNeuronHeight++; //move to the row below
        this->currentNeuronWidth = 0;
    }
}