#include "FeatureDetector.h"

FeatureDetector::FeatureDetector(int height, int width)
	: detectorHeight{ height }, detectorWidth{width}
{
	weights = std::vector<double>(height * width);
	randomizeWeights();
}

void FeatureDetector::randomizeWeights()
{
	for (double& featureCell : weights)
		featureCell = rand() / RAND_MAX;
}

double FeatureDetector::getWeight(int height, int width)
{
	if (height < detectorHeight && width < detectorHeight)
		return weights[height * detectorHeight + width];
	else throw std::exception{ "przypau" };
}

void FeatureDetector::add()
{
	throw std::exception{ "cant manually add a weight to a feature detector" };
}


