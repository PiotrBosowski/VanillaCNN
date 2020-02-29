#pragma once
#include "Layer2D.h"
#include <vector>
#include <memory>
#include "ConnectingModes.h"


class ConvolutionLayer : public Layer2D
{
public:
	ConvolutionLayer(int numberOfFeatureDetectors, int featureDetectorHeight, int featureDetectorWidth);

private:
	int featureDetectorHeight;
	int featureDetectorWidth;
	ConnectingModes mode = ONE_TO_MANY;
public:
	int getFeatureDetectorHeight();
	int getFeatureDetectorWidth();

	void populateNeurons(std::unique_ptr<Layer>& previousLayer) override;
	void print() override;
};
