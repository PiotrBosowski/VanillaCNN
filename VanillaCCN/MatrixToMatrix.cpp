#include "MatrixToMatrix.h"
#include <iostream>
#include "Layer2D.h"
#include <vector>
#include "DownsamplingLayer.h"
#include "ConvolutionLayer.h"
#include <memory>

void MatrixToMatrix::connect(std::unique_ptr<Layer>& preceding, std::unique_ptr<Layer>& following)
{
	std::cout << "connecting matrix to matrix: ";
	int counter;
	if (dynamic_cast<ConvolutionLayer*>(following.get()))
	{
		counter = connectToConvolution(static_cast<Layer2D*>(preceding.get()), static_cast<ConvolutionLayer*>(following.get()));
	}
	else if(dynamic_cast<DownsamplingLayer*>(following.get()))
	{
		counter = connectToDownsampling(static_cast<Layer2D*>(preceding.get()), static_cast<DownsamplingLayer*>(following.get()));
	}
	else
	{
		throw std::exception{ "error with connecting 2dTo2d layers: following layer isnt Convolution nor Downsampling" };
	}
	std::cout << counter << " connections made" << std::endl;
}

int MatrixToMatrix::connectToConvolution(Layer2D* preceding, ConvolutionLayer* convolution)
{
	int counter = 0;
	int featureHeight = convolution->getFeatureDetectorHeight();
	int featureWidth = convolution->getFeatureDetectorWidth();
	auto& precedingMatrices = preceding->getMatrices();
	auto& convolutionMatrices = convolution->getMatrices();
	int precedingSize = precedingMatrices.size();
	int convolutionSize = convolutionMatrices.size();
	for (unsigned int i = 0; i < convolutionSize; i++)
		for (unsigned int j = 0; j < precedingSize; j++)
			counter += connectMatrices(precedingMatrices[j], convolutionMatrices[i], featureHeight, featureWidth);
	return counter;
}

int MatrixToMatrix::connectMatrices(std::unique_ptr<Matrix>& preceding, std::unique_ptr<Matrix>& downsampling, int featureHeight, int featureWidth)
{
	int counter = 0;
	auto& precedingMatrix = preceding.get()->getMatrix();
	auto& downsamplingMatrix = downsampling.get()->getMatrix();
	int height = downsampling.get()->getMatrixHeight();
	int width = downsampling.get()->getMatrixWidth();
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			for (int m = 0; m < featureHeight; m++)
				for (int n = 0; n < featureWidth; n++)
				{
					Connection(precedingMatrix[i + m][j + n], downsamplingMatrix[i][j]);
					counter++;
				}
	return counter;
}

int MatrixToMatrix::connectToDownsampling(Layer2D* preceding, DownsamplingLayer* downsampling) //ONE TO ONE
{
	int counter = 0;
	int featureHeight = downsampling->getDownsamplerHeight();
	int featureWidth = downsampling->getDownsamplerWidth();
	int numberOfMatrices = downsampling->getMatrices().size();
	auto& precedingMatrices = preceding->getMatrices();
	auto& downsamplingMatrices = downsampling->getMatrices();
	if(precedingMatrices.size() != downsamplingMatrices.size()) throw std::exception{ "ERROR: sizes of layers doesnt match for OneToOne connection" };
	for (unsigned int i = 0; i < downsamplingMatrices.size(); i++)
	{
		counter += connectMatrices(precedingMatrices[i], downsamplingMatrices[i], featureHeight, featureWidth);
	}
	return counter;
}

