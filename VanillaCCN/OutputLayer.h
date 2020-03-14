#pragma once
#include "Layer.h"
#include "Layer1D.h"

class OutputLayer : public Layer1D
{
public:
	OutputLayer(int numberOfNeurons);

public:
	std::string getSummary() override;
};
