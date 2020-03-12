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
	void populateNeurons(Layer& previousLayer) override;
	void populateNeurons() override;
	void print() override;
	void connect(Layer& previousLayer) override; //connects previous layer to this one
	~InputLayer();
};
