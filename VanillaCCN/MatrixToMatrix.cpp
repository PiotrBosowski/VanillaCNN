#include "MatrixToMatrix.h"
#include <iostream>
#include "Layer2D.h"
#include <vector>
#include "DownsamplingLayer.h"
#include "ConvolutionLayer.h"
#include <memory>

void MatrixToMatrix::connect(Layer& preceding, Layer& following)
{
	std::cout << "connecting matrix to matrix: ";
	int counter;
	if (dynamic_cast<ConvolutionLayer*>(&following))
	{
		counter = connectToConvolution(static_cast<Layer2D&>(preceding), static_cast<ConvolutionLayer&>(following));
	}
	else if(dynamic_cast<DownsamplingLayer*>(&following))
	{
		counter = connectToDownsampling(static_cast<Layer2D&>(preceding), static_cast<DownsamplingLayer&>(following));
	}
	else
	{
		throw std::exception{ "error with connecting 2dTo2d layers: following layer isnt Convolution nor Downsampling" };
	}
	std::cout << counter << " connections made" << std::endl;
}

int MatrixToMatrix::connectToConvolution(Layer2D& preceding, ConvolutionLayer& convolution)
{
	int counter = 0;
	int featureHeight = convolution.getFeatureDetectorHeight();
	int featureWidth = convolution.getFeatureDetectorWidth();
	auto& precedingMatrices = preceding.getMatrices();
	auto& convolutionMatrices = convolution.getMatrices();
	int precedingSize = (int)precedingMatrices.size();
	int convolutionSize = (int)convolutionMatrices.size();
	for (int i = 0; i < convolutionSize; i++)
		for (int j = 0; j < precedingSize; j++)
			counter += connectMatricesDownsampling(precedingMatrices[j], convolutionMatrices[i], featureHeight, featureWidth); //to jest zle, bedzie sie psuc
	return counter;
}

int MatrixToMatrix::connectMatricesDownsampling(std::unique_ptr<Matrix>& preceding, std::unique_ptr<Matrix>& following, int featureHeight, int featureWidth)
{
	int counter = 0;
	auto precedingMatrix = preceding.get();
	auto followingMatrix = following.get();
	int height = following.get()->getMatrixHeight();
	int width = following.get()->getMatrixWidth();
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			for (int m = 0; m < featureHeight; m++)
				for (int n = 0; n < featureWidth; n++)
				{
					followingMatrix->getNeuron(i, j).acceptConnection(precedingMatrix->getNeuron(i + m, j + n));
					counter++;
				}
	return counter;
}

int MatrixToMatrix::connectToDownsampling(Layer2D& preceding, DownsamplingLayer& downsampling) //ONE TO ONE
{
	int counter = 0;
	int featureHeight = downsampling.getDownsamplerHeight();
	int featureWidth = downsampling.getDownsamplerWidth();
	int numberOfMatrices = (int)downsampling.getMatrices().size();
	auto& precedingMatrices = preceding.getMatrices();
	auto& downsamplingMatrices = downsampling.getMatrices();
	if(precedingMatrices.size() != downsamplingMatrices.size()) throw std::exception{ "ERROR: sizes of layers doesnt match for OneToOne connection" };
	for (unsigned int i = 0; i < downsamplingMatrices.size(); i++)
	{
		counter += connectMatricesDownsampling(precedingMatrices[i], downsamplingMatrices[i], featureHeight, featureWidth);
	}
	return counter;
}

