//
// Created by piotr on 20/04/11.
//

#include "NeuronsConnecting1toArea.h"
#include "../Containers/Matrices/Matrix.h"
#include "../exceptions/Exceptions.h"

NeuronsConnecting1toArea::NeuronsConnecting1toArea(int areaHeight, int areaWidth)
        : areaHeight{ areaHeight },
          areaWidth{ areaWidth }
{}

std::vector<Neuron *>
NeuronsConnecting1toArea::proposeSingleNeuronConnections(unsigned neuronIndex, Container &source, Container *preceding) {
    auto sourceMatrix = dynamic_cast<Matrix*>(&source);
    auto previousMatrix = dynamic_cast<Matrix*>(preceding);
    if (!sourceMatrix && !previousMatrix)
        throw ConnectingException("Cannot use 1 to Area type of connection with 1D containers.");

    std::vector<Neuron*> result;
    auto sourceHeight = sourceMatrix->getHeightFromIndex(neuronIndex);
    auto sourceWidth= sourceMatrix->getWidthFromIndex(neuronIndex);
    for (int i = 0; i < this->areaHeight; ++i) {
        for (int j = 0; j < this->areaWidth; ++j) {
            result.emplace_back(&previousMatrix->getNeuron(sourceHeight + i, sourceWidth + j));
        }
    }
    return result;
}

