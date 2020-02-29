#pragma once
#include "Layer2D.h"
#include "ConnectingModes.h"
#include <memory>

class DownsamplingLayer : public Layer2D
{
public:
	DownsamplingLayer(int downsamplerHeight, int downsamplerWidth);

private:
	int downsamplerHeight;
	int downsamplerWidth;
	ConnectingModes mode = ONE_TO_ONE;
public: 
	int getDownsamplerHeight();
	int getDownsamplerWidth();

	void populateNeurons(std::unique_ptr<Layer>& previousLayer) override;
	void print() override;
	virtual ~DownsamplingLayer();
};
