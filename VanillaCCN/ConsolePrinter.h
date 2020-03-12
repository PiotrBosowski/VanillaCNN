#pragma once
#include <string>
#include <iostream>

class NeuralNetwork;

class ConsolePrinter
{
public:
	ConsolePrinter(const NeuralNetwork& source, bool printingEnabled = true);

private:
	const NeuralNetwork& motherNetwork;
	bool printingEnabled;
public:
	void print(std::string description = "");
	void printError(std::string error);
};

