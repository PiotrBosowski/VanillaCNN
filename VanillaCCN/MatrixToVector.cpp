#include "MatrixToVector.h"
#include <iostream>
#include "Layer2D.h"
#include "Layer1D.h"

void MatrixToVector::connect(Layer& preceding, Layer& following)
{
	std::cout << "connecting matrix to vector: ";
	Layer2D& precedingLayer2D = static_cast<Layer2D&>(preceding);
	Layer1D& followingLayer1D = static_cast<Layer1D&>(following);
	auto& precedingMatrices = precedingLayer2D.getMatrices();
	auto& followingNeurons = followingLayer1D.getNeurons();
	int counter = 0;
	for (auto& precedingMatrixPtr : precedingMatrices)
	{
		Matrix& perceding = *precedingMatrixPtr;
		for (int i = 0; i < perceding.getMatrixHeight(); i++)
		{
			for (int j = 0; j < perceding.getMatrixWidth(); j++)
			{
				Neuron& precedingNeuron = perceding.getNeuron(i, j);
				for (auto& followingNeuron : followingNeurons)
				{
					(*followingNeuron).acceptConnection(precedingNeuron);
					counter++;
				}
			}
		}
	}
	std::cout << counter << " connections made" << std::endl;
}
