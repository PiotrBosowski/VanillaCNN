#include "ConsolePrinter.h"

constexpr char RESET[]{ "\033[0m" };
constexpr char RED[]{ "\033[31m" };
constexpr char GREEN[]{ "\033[32m" };
constexpr char YELLOW[]{ "\033[33m" };
constexpr char BLUE[]{ "\033[34m" };
constexpr char MAGENTA[]{ "\033[35m" };
constexpr char CYAN[]{ "\033[36m" };
constexpr char WHITE[]{ "\033[37m" };

ConsolePrinter::ConsolePrinter(const OutputSource& source, bool printingEnabled)
	: OutputPrinter{ source, printingEnabled }
{
}

void ConsolePrinter::print(std::string description)
{
	if (description != "")
		std::cout << GREEN << description << RESET << std::endl;
	auto& layers = source.getStructure();
	for (auto& layer : layers) {
		std::cout << layer->getSummary() << std::endl;
	}
	if (description != "")
		std::cout << std::endl;
}

void ConsolePrinter::printError(std::string error)
{
	std::cerr << RED << "ERROR: {" << error << "}" << RESET << std::endl;
}
