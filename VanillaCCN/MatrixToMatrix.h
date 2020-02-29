#pragma once
#include "ConnectingStrategy.h"
#include <vector>
#include <memory>
#include "Layer.h"
#include "Layer2D.h"
#include "matrix.h"
#include "DownsamplingLayer.h"
#include "ConvolutionLayer.h"

class MatrixToMatrix : public ConnectingStrategy
{
public:
	void connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) override;

private:
	int connectToConvolution(Layer2D* preceding, ConvolutionLayer* following);
	int connectMatrices(std::unique_ptr<Matrix>& preceding, std::unique_ptr<Matrix>& downsampling, int featureHeight, int featureWidth);
	int connectToDownsampling(Layer2D* preceding, DownsamplingLayer* following);
};

