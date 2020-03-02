#pragma once
#include "Layer.h"
#include <vector>
#include <memory>

class ConnectingStrategy
{
public:
	virtual void connect(Layer& first, Layer& second) = 0;
};

