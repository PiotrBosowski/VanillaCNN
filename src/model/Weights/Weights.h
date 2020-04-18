//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTS_H
#define VANILLACNN_CLION_WEIGHTS_H


#include <vector>

class Weights
{
public:
    explicit Weights(int height, int width);
    explicit Weights(int length);
protected:
    std::vector<double> weights;
public:
    double& getWeight(int index);
};



/*

#pragma once
#include <vector>
#include "Weights.h"

class FeatureDetector : public Weights
{
public:
	FeatureDetector(int height, int width);

private:
	int detectorHeight;
	int detectorWidth;
	void randomizeWeights();

public:
	double getWeight(int height, int width);
	void add() override; //FeatureDetector overrides it so u cant use the function unintentionally
};





*/


#endif //VANILLACNN_CLION_WEIGHTS_H
