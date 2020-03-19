#include "MatrixConv.h"

MatrixConv::MatrixConv(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth, int featureDetectorHeight, int featureDetectorWidth)
	: Matrix{ neuronFactory, neuronsConnectingStrategy, matrixHeight, matrixWidth }, featureDetector{ FeatureDetector{featureDetectorHeight, featureDetectorWidth} }
{
}
