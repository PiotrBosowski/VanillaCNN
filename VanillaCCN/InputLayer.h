#pragma once
#include "Layer.h"
#include "Layer2D.h"
#include "ConvolutionLayer.h"
#include "FullyConnectedLayer.h"
#include <vector>

class InputLayer : public Layer2D
{
public:
	InputLayer(int inputHeight, int inputWidth);
	void createContainers() override;
	std::string getSummary() override;
	void connectToPreceeding() override; //connects previous layer to this one
};
