#include "VectorToMatrix.h"
#include <iostream>

std::vector<std::unique_ptr<Connection>> VectorToMatrix::connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
{
	std::cout << "connecting vector to matrix" << std::endl;
	return std::vector<std::unique_ptr<Connection>>();
}
