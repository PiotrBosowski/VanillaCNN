#pragma once
#include <memory>
#include <vector>
#include "Layer.h"
#include "OutputPrinter.h"

class OutputSource
{
public:
	OutputSource(bool printingEnabled = true);

protected:
	std::unique_ptr<OutputPrinter> printer;

private:
	bool printingEnabled;

public:
	virtual const std::vector<std::shared_ptr<Layer>>& getOutput() const = 0;
};

