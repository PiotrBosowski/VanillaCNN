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

	void createContainers() override;
	std::string getSummary() override;
};
