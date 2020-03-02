#pragma once
#include "ConnectingStrategy.h"

class MatrixToVector : public ConnectingStrategy
{
public:
	void connect(Layer& first, Layer& second) override;
};

