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

	void print() override;
	~InputLayer();
};

