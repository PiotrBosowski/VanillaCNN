#pragma once
#include "Layer.h"
#include "Layer1D.h"

class OutputLayer : public Layer1D
{
public:
	OutputLayer(int numberOfNeurons);

public:
	void print() override;
	void populateNeurons() override;
	~OutputLayer();
};

