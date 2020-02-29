
#pragma once
#include "Layer.h"
#include "ConnectingStrategy.h"
#include "Connection.h"
#include <vector>
#include <memory>

class ConnectingEngine
{
public:
	ConnectingEngine(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second);

private:
	std::unique_ptr<Layer>& first;
	std::unique_ptr<Layer>& second;
	std::unique_ptr<ConnectingStrategy> strategy;
	std::unique_ptr<ConnectingStrategy> evaluateStrategy();

public:
	std::vector<std::unique_ptr<Connection>> run();
};
