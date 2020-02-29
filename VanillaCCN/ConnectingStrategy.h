#pragma once
#include "Layer.h"
#include <vector>
#include "Connection.h"
#include <memory>

class ConnectingStrategy
{
public:
	virtual std::vector<std::unique_ptr<Connection>> connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) = 0;
};

