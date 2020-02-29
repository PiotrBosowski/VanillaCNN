#include "MatrixToVector.h"
#include <iostream>
#include "Layer2D.h"
#include "Layer1D.h"

void MatrixToVector::connect(std::unique_ptr<Layer>& preceding, std::unique_ptr<Layer>& following)
{
	std::cout << "connecting matrix to vector: ";
	Layer2D* precedingLayer2D = static_cast<Layer2D*>(preceding.get());
	Layer1D* followingLayer1D = static_cast<Layer1D*>(following.get());
	auto& precedingMatrices = precedingLayer2D->getMatrices();
	auto& followingNeurons = followingLayer1D->getNeurons();
	int counter = 0;
	for (auto& precedingMatrix : precedingMatrices)
	{
		auto& matrix = precedingMatrix.get()->getMatrix();
		for (auto& row : matrix)
		{
			for (auto& neuron : row)
			{
				for (auto& followingNeuron : followingNeurons)
				{
					Connection(neuron, followingNeuron);
					counter++;
				}
			}
		}
	}
	std::cout << counter << " connections made" << std::endl;
}
