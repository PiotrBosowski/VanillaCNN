//
// Created by piotr on 20/04/11.
//

#include "NeuronsConnecting1toArea.h"
#include "Containers/Matrices/Matrix.h"
#include "Exceptions/Exceptions.h"

NeuronsConnecting1toArea::NeuronsConnecting1toArea(int areaHeight, int areaWidth, int verticalStride, int horizontalStride)
        : areaHeight{ areaHeight },
          areaWidth{ areaWidth },
          verticalStride{verticalStride},
          horizontalStride{horizontalStride}
{
    if(areaHeight < 1 || areaWidth < 1 || verticalStride < 1 || horizontalStride < 1)
        throw LayersConnectingException("cannot create NeuronsConnecting1toArea strategy with negative values");
    if(verticalStride > areaHeight || horizontalStride > areaWidth)
        throw LayersConnectingException("cannot create NeuronsConnecting1toArea strategy with stride bigger than area");
}

std::vector<Neuron *>
NeuronsConnecting1toArea::proposeSingleNeuronConnections(unsigned neuronIndex, Container &source, Container &preceding) {
    //validation:
    auto& sourceMatrix = dynamic_cast<Matrix&>(source);
    auto& previousMatrix = dynamic_cast<Matrix&>(preceding);
    if((previousMatrix.getMatrixHeight() - areaHeight)%verticalStride != 0 || //if you cant cover whole height dimension OR
        (previousMatrix.getMatrixWidth() - areaWidth)%horizontalStride != 0 || //if you cant cover whole width dimension OR
        sourceMatrix.getMatrixHeight() - 1 != (previousMatrix.getMatrixHeight()-areaHeight)/verticalStride ||
        sourceMatrix.getMatrixWidth() - 1 != (previousMatrix.getMatrixWidth()-areaWidth)/horizontalStride)
            throw LayersConnectingException("incorrect NeuronsConnecting1toArea parameters - neuron leak detected");
    //validation-end
    // throws bad_cast if requirements not met
    std::vector<Neuron*> result;
    auto sourceHeight = sourceMatrix.getHeightFromIndex(neuronIndex);
    auto sourceWidth = sourceMatrix.getWidthFromIndex(neuronIndex);
    for (int i = 0; i < this->areaHeight; ++i) {
        for (int j = 0; j < this->areaWidth; ++j) {
            result.emplace_back(&previousMatrix.getNeuron(sourceHeight * verticalStride + i, sourceWidth * horizontalStride + j));
        }
    }
    return result;
}

