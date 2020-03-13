#pragma once
#include "Layer.h"
#include "matrix.h"
#include "Vector.h"
#include <vector>
#include "Layer1D.h"
#include <iostream>
#include <memory>

class Layer1D : public Layer
{
public:
	Layer1D(int vectorLength);

protected:
	int vectorLength;

public:
	void createContainers() override;
	std::string getSummary();
};