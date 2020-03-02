#pragma once
#include "Layer.h"
#include "ConnectingStrategy.h"
#include <vector>
#include <memory>

class ConnectingEngine
{
public:
	ConnectingEngine(Layer& first, Layer& second);

private:
	Layer& first;
	Layer& second;
	std::unique_ptr<ConnectingStrategy> strategy;
	std::unique_ptr<ConnectingStrategy> evaluateStrategy();

public:
	void run();
};
