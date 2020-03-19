#include "OutputSource.h"
#include "ConsolePrinter.h"

OutputSource::OutputSource(bool printingEnabled)
	: printingEnabled{ printingEnabled }, printer{ std::make_unique<ConsolePrinter>(*this, printingEnabled) }
{
}
