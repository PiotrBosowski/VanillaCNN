//
// Created by piotr on 20/04/11.
//


#include "ConsolePrinter.h"
#include "OutputSource.h"

ConsolePrinter::ConsolePrinter(OutputSource& source, bool printingEnabled)
        : OutputPrinter{ source, printingEnabled }
{
}

void ConsolePrinter::print(std::string description)
{
    std::cout << description << std::endl;
    const auto& text = source.getOutput();
    std::cout << text << std::endl;
}

void ConsolePrinter::printError(std::string error)
{
    std::cerr  << "ERROR: " << error << std::endl;
}
