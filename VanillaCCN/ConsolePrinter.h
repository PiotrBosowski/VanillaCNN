#pragma once
#include <string>
#include <iostream>
#include "OutputSource.h"
#include "OutputPrinter.h"

class ConsolePrinter : public OutputPrinter
{
public:
	ConsolePrinter(const OutputSource& source, bool printingEnabled = true);

public:
	void print(std::string description = "") override;
	void printError(std::string error) override;
};

