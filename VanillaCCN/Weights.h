#pragma once
#include <vector>

class Weights
{
public:
	Weights();
private:
	std::vector<double> weights;
public:
	double get(int index) const;
};
