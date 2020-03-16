#pragma once
#include <string>
#include <iostream>
#include "OutputSource.h"


class OutputPrinter
{
public:
	OutputPrinter(const OutputSource& source, bool printingEnabled = true);

protected:
	const OutputSource& source;
	bool printingEnabled;

public:
	virtual void print(std::string description = "") = 0;
	virtual void printError(std::string error) = 0;
};
