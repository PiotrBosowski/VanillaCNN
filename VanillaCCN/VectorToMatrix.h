#pragma once
#include "ConnectingStrategy.h"

class VectorToMatrix : public ConnectingStrategy
{
public:
	void connect(Layer& first, Layer& second) override;
};

