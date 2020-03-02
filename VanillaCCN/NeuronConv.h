#pragma once
#include "Neuron.h"
#include "Container.h"
#include "FeatureDetector.h"
#include <functional>

/*
Class for neurons of convolution layers.
They store vector of connected neurons and a reference to a feature detecor matrix.
*/
class NeuronConv : public Neuron
{
public:
	NeuronConv(FeatureDetector& featureDetector);
private:
	FeatureDetector& featureDetector; //std::reference_wrapper<FeatureDetector> featureDetector;
	std::vector<std::reference_wrapper<Neuron>> connections;

public:
	void acceptConnection(Neuron& preceding) override;
	virtual void calculateValue() override;
};
