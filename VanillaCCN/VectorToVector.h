#pragma once
#include "ConnectingStrategy.h"
#include "Connection.h"

class VectorToVector : public ConnectingStrategy
{
public:
	std::vector<std::unique_ptr<Connection>> connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) override;
};
