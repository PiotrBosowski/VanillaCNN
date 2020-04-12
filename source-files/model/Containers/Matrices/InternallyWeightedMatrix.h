//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
#define VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H


#include "Matrix.h"
#include "../../Neurons/Weights.h"
class InternallyWeightedMatrix : public Matrix
{
public:
    InternallyWeightedMatrix(NeuronsConnectingStrategy& neuronsConnectingStrategy, int matrixHeight, int matrixWidth, int weightsHeight, int weightsWidth);

private:
    int weightsHeight;
    int weightsWidth;
    std::unique_ptr<Weights> weights; //in case of future weights inheritance
};



/*
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



*/

#endif //VANILLACNN_CLION_INTERNALLYWEIGHTEDMATRIX_H
