#include "VectorToVector.h"
#include <iostream>
#include "Layer1D.h"
#include "Connection.h"
#include <vector>

void VectorToVector::connect(std::unique_ptr<Layer>& preceding, std::unique_ptr<Layer>& following)
{
	
	std::cout << "connecting vector to vector: ";
	Layer1D* precedingLayer1D = static_cast<Layer1D*>(preceding.get());
	Layer1D* followingLayer1D = static_cast<Layer1D*>(following.get());
	std::vector<std::unique_ptr<Neuron>>& precedingVector = precedingLayer1D->getNeurons();
	std::vector<std::unique_ptr<Neuron>>& followingVector = followingLayer1D->getNeurons();
	int counter = 0;
	for (auto& followingNeuron: followingVector)
	{
		for (auto& precedingNeuron : precedingVector)
		{
			Connection(precedingNeuron, followingNeuron); //saved to following neuron
			counter++;
		}
	}
	std::cout << counter << " connections made"<< std::endl;
}
