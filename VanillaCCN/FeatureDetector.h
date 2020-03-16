#pragma once
#include <vector>
#include "Weights.h"

class FeatureDetector : public Weights
{
public:
	FeatureDetector(int height, int width);

private:
	int detectorHeight;
	int detectorWidth;
	void randomizeWeights();

public:
	double getWeight(int height, int width);
	void add() override; //FeatureDetector overrides it so u cant use the function unintentionally
};
