#include "MatrixConv.h"

MatrixConv::MatrixConv(NeuronFactory& neuronFactory, NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth)
	: Matrix{ neuronFactory, neuronsConnectingStrategy, matrixHeight, matrixWidth }, featureDetector{ FeatureDetector{matrixHeight, matrixWidth} }
{
}
