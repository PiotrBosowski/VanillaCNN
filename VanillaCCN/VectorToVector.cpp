#include "VectorToVector.h"
#include <iostream>
#include "Layer1D.h"
#include <vector>

void VectorToVector::connect(Layer& preceding, Layer& following)
{
	std::cout << "connecting vector to vector: ";
	Layer1D& precedingLayer1D = static_cast<Layer1D&>(preceding);
	Layer1D& followingLayer1D = static_cast<Layer1D&>(following);
	int counter = 0;
	for (auto& followingNeuron: followingLayer1D.getNeurons())
	{
		for (auto& precedingNeuron : precedingLayer1D.getNeurons())
		{
			(*followingNeuron).acceptConnection((*precedingNeuron));
			counter++;
		}
	}
	std::cout << counter << " connections made"<< std::endl;
}
