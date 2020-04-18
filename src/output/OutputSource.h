//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_OUTPUTSOURCE_H
#define VANILLACNN_CLION_OUTPUTSOURCE_H


#include <memory>
#include <vector>
#include "../model/Layers/Layer.h"
#include "OutputPrinter.h"

class OutputSource
{
public:
    explicit OutputSource(bool printingEnabled = true);

protected:
    std::unique_ptr<OutputPrinter> printer;

protected:
    bool printingEnabled;

public:
    [[nodiscard]] virtual std::string getOutput() const = 0;
};


#endif //VANILLACNN_CLION_OUTPUTSOURCE_H
