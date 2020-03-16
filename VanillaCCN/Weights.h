#pragma once
#include <vector>

class Weights
{
public:
	Weights();
protected:
	std::vector<double> weights;
public:
	double getWeight(int index);
	virtual void add(); //FeatureDetector overrides it so u cant use the function unintentionally
};
