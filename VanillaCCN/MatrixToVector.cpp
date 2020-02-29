#include "MatrixToVector.h"
#include <iostream>

void MatrixToVector::connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
{
	std::cout << "connecting matrix to vector: ";
	std::cout << "0 connections made" << std::endl;
}
