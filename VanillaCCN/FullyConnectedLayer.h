#pragma once
#include "Layer.h"
#include "Layer1D.h"

class FullyConnectedLayer : public Layer1D
{
public:
	FullyConnectedLayer(int numberOfNeurons);

public:
	void print() override;
};
