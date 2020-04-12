//
// Created by piotr on 20/04/11.
//

#include "NeuronsConnecting1toArea.h"
#include "../Containers/Matrices/Matrix.h"
#include "../exceptions/Exceptions.h"

NeuronsConnecting1toArea::NeuronsConnecting1toArea(int areaHeight, int areaWidth)
        : areaHeight{ areaHeight },
          areaWidth{ areaWidth }
{
}

void NeuronsConnecting1toArea::connect(Container& sourceContainer, Container& previousContainer)
{
    auto sourceMatrix = dynamic_cast<Matrix*>(&sourceContainer);
    auto previousMatrix = dynamic_cast<Matrix*>(&previousContainer);
    if (!sourceMatrix && !previousMatrix)
        throw ConnectingException("Cannot use 1 to Area type of connection with 1D containers.");
    for (int sourceY = 0; sourceY < sourceMatrix->getMatrixHeight(); sourceY+= areaWidth) //TODO: iterator / for all neurons in container
    {
        for (int sourceX = 0; sourceX < sourceMatrix->getMatrixWidth(); sourceX += areaWidth)
        {
            Neuron& sourceNeuron = sourceMatrix->getNeuron(sourceY, sourceX);
            for (int previousY = 0; previousY < areaHeight; previousY++)
            {
                for (int previousX = 0; previousX < areaWidth; previousX++)
                {
                    Neuron& previousNeuron = previousMatrix->getNeuron(sourceY * areaHeight + previousY, sourceX * areaWidth + previousX);
                    sourceNeuron.connect(previousNeuron);
                }
            }
        }
    }
}