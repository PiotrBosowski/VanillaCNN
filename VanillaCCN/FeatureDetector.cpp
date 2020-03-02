#include "FeatureDetector.h"

FeatureDetector::FeatureDetector(int height, int width)
	: detectorHeight{ height }, detectorWidth{width}
{
	featureMatrix = std::vector<double>(height * width);
	randomizeWeights();
}

void FeatureDetector::randomizeWeights()
{
	for (double& featureCell : featureMatrix)
		featureCell = rand() / RAND_MAX;
}

double FeatureDetector::getFeatureWeight(int index)
{
	return featureMatrix[index];
}
