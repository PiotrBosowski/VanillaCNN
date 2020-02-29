#pragma once
#include "ConnectingStrategy.h"

class MatrixToVector : public ConnectingStrategy
{
public:
	void connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) override;
};

