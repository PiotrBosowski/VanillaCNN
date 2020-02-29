#pragma once
#include "Layer.h"
#include <vector>
#include "Connection.h"
#include <memory>

class ConnectingStrategy
{
public:
	virtual void connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) = 0;
};

