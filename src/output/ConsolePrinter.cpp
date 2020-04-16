//
// Created by piotr on 20/04/11.
//


#include "ConsolePrinter.h"
#include "OutputSource.h"

constexpr char RESET[]{"\033[0m" };
constexpr char RED[]{ "\033[31m" };
constexpr char GREEN[]{ "\033[32m" };
constexpr char YELLOW[]{ "\033[33m" };
constexpr char BLUE[]{ "\033[34m" };
constexpr char MAGENTA[]{ "\033[35m" };
constexpr char CYAN[]{ "\033[36m" };
constexpr char WHITE[]{ "\033[37m" };

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
