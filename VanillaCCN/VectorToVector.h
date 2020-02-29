#pragma once
#include "ConnectingStrategy.h"
#include "Connection.h"

class VectorToVector : public ConnectingStrategy
{
public:
	void connect(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second) override;
};
