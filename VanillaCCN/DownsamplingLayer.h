#pragma once
#include "Layer2D.h"
#include <memory>

class DownsamplingLayer : public Layer2D
{
public:
	DownsamplingLayer(int downsamplerHeight, int downsamplerWidth);

private:
	int downsamplerHeight;
	int downsamplerWidth;
public: 
	int getDownsamplerHeight();
	int getDownsamplerWidth();

	void populateNeurons(Layer& previousLayer) override;
	void populateNeurons() override;
	void print() override;
	virtual ~DownsamplingLayer();
};
