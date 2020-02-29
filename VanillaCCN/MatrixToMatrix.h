#pragma once
#include "ConnectingStrategy.h"

class MatrixToMatrix : public ConnectingStrategy
{
public:
	std::vector<std::unique_ptr<Connection>> connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) override;
};

