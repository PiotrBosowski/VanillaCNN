//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_OUTPUTPRINTER_H
#define VANILLACNN_CLION_OUTPUTPRINTER_H

#include <string>
#include <iostream>

class OutputSource;

class OutputPrinter
{
public:
    OutputPrinter(OutputSource& source, bool printingEnabled = true);

protected:
    OutputSource& source;
    bool printingEnabled;

public:
    virtual void print(std::string description = "") = 0;
    virtual void printError(std::string error) = 0;
};



#endif //VANILLACNN_CLION_OUTPUTPRINTER_H
