#pragma once
#include "Matrix.h"
#include "FeatureDetector.h"
#include "NeuronsConnectingStrategy.h"

class MatrixConv : public Matrix
{
public:
	MatrixConv(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth, int featureDetectorHeight, int featureDetectorWidth);

private:
	FeatureDetector featureDetector;
};

