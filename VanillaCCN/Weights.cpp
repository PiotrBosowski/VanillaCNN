#include "Weights.h"

Weights::Weights()
{
}

double Weights::getWeight(int index)
{
	return weights[index];
}

void Weights::add()
{
	weights.push_back(0.1);
}