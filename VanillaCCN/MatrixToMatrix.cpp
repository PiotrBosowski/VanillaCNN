#include "MatrixToMatrix.h"
#include <iostream>

std::vector<std::unique_ptr<Connection>> MatrixToMatrix::connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
{
	std::cout << "connecting matrix to matrix: ";
	int counter = 0;
	std::cout << counter << " connections made" << std::endl;
	return std::vector<std::unique_ptr<Connection>>();
}
