#include "VectorToVector.h"
#include <iostream>
#include "Layer1D.h"
#include "Connection.h"
#include <vector>

std::vector<std::unique_ptr<Connection>> VectorToVector::connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
{
	
	std::cout << "connecting vector to vector: ";
	Layer1D* firstLayer1D = static_cast<Layer1D*>(first.get());
	Layer1D* secondLayer1D = static_cast<Layer1D*>(second.get());
	std::vector<std::unique_ptr<Neuron>>& firstVector = firstLayer1D->getNeurons();
	std::vector<std::unique_ptr<Neuron>>& secondVector = secondLayer1D->getNeurons();
	std::vector<std::unique_ptr<Connection>> output;
	int counter = 0;
	for (auto& secondNeuron: secondVector)
	{
		for (auto& firstNeuron : firstVector)
		{
			//output.push_back(std::move(std::unique_ptr<Connection>{new Connection{ firstNeuron, secondNeuron }}));
			counter++;
		}
	}
	std::cout << counter << " connections made"<< std::endl;
	//return output;
	
	return std::vector<std::unique_ptr<Connection>>();
}
