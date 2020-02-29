#pragma once
#include "Layer2D.h"
#include <vector>
#include <memory>


class ConvolutionLayer : public Layer2D
{
public:
	ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth);

private:
	int featureDetectorHeight;
	int featureDetectorWidth;
public:
	int getFeatureDetectorHeight();
	int getFeatureDetectorWidth();

	void populateNeurons(std::unique_ptr<Layer>& previousLayer) override;
	void print() override;
};
