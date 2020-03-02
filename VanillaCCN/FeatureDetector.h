#pragma once
#include <vector>

class FeatureDetector
{
public:
	FeatureDetector(int height, int width);

private:
	int detectorHeight;
	int detectorWidth;
	void randomizeWeights();
	std::vector<double> featureMatrix;

public:
	double getFeatureWeight(int index);
};


