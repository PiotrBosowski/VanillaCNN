#pragma once
#include "Layer2D.h"
#include <vector>
#include "FeatureDetector.h"
#include "ConvolutionLayerConnector.h"
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

	void populateNeurons(Layer& previousLayer) override;
	void populateNeurons() override;
	void connect(Layer& previousLayer) override;
	std::string getSummary() override;
};
