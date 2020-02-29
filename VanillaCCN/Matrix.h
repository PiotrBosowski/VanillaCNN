#pragma once
#include <vector>
#include <memory>
#include "Neuron.h"

class Matrix
{
public: 
	Matrix(int matrixHeight, int matrixWidth);
	//Matrix(const Matrix &) = delete;
private: 
	int matrixHeight;
	int matrixWidth;
	std::vector<std::vector<std::unique_ptr<Neuron>>> matrix;
	//std::vector<std::unique_ptr<Neuron>> matrix;
	//std::unique_ptr<Neuron> matrix;
	//Neuron matrix;
public:
	int getMatrixHeight();
	int getMatrixWidth();
	//std::vector<std::vector<std::unique_ptr<Neuron>>>& getMatrix();
};
