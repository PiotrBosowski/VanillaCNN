#pragma once
#include <vector>
#include <memory>
#include "Layer.h"

class OutputSource
{
public:
	virtual const std::vector<std::shared_ptr<Layer>>& getStructure() const = 0;
};

