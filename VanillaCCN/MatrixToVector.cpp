#include "MatrixToVector.h"
#include <iostream>

std::vector<std::unique_ptr<Connection>> MatrixToVector::connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
{
	std::cout << "connecting matrix to vector: ";
	std::cout << "0 connections made" << std::endl;
	return std::vector<std::unique_ptr<Connection>>();
}
