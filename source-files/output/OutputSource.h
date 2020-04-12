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
    OutputSource(bool printingEnabled = true);

protected:
    std::unique_ptr<OutputPrinter> printer;

private:
    bool printingEnabled;

public:
    virtual const std::vector<std::shared_ptr<Layer>>& getOutput() const = 0;
};


#endif //VANILLACNN_CLION_OUTPUTSOURCE_H
