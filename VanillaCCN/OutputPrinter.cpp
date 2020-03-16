#include "OutputSource.h"
#include "OutputPrinter.h"

OutputPrinter::OutputPrinter(const OutputSource& source, bool printingEnabled)
	: source{ source }
{
}
