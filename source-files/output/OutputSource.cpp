//
// Created by piotr on 20/04/11.
//


#include "OutputSource.h"
#include "ConsolePrinter.h"

OutputSource::OutputSource(bool printingEnabled)
        : printingEnabled{ printingEnabled }, printer{ std::make_unique<ConsolePrinter>(*this, printingEnabled) }
{
}
