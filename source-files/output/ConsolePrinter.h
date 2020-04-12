//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_CONSOLEPRINTER_H
#define VANILLACNN_CLION_CONSOLEPRINTER_H


#include <string>
#include <iostream>
#include "OutputPrinter.h"

class OutputSource;

class ConsolePrinter : public OutputPrinter
{
public:
    explicit ConsolePrinter(OutputSource& source, bool printingEnabled = true);

public:
    void print(std::string description) override;
    void printError(std::string error) override;
};


#endif //VANILLACNN_CLION_CONSOLEPRINTER_H
