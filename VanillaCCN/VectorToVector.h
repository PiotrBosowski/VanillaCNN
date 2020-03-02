#pragma once
#include "ConnectingStrategy.h"

class VectorToVector : public ConnectingStrategy
{
public:
	void connect(Layer& first, Layer& second) override;
};
