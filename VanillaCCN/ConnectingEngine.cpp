
#include "ConnectingEngine.h"
#include "Layer2D.h"
#include "ConnectingStrategy.h"
#include "MatrixToMatrix.h"
#include "MatrixToVector.h"
#include "VectorToMatrix.h"
#include "VectorToVector.h"
#include "Connection.h"
#include <memory>

ConnectingEngine::ConnectingEngine(std::unique_ptr<Layer>& first, std::unique_ptr<Layer>& second)
	: first{ first }, second{second}
{
	strategy = evaluateStrategy();
}

std::vector<std::unique_ptr<Connection>> ConnectingEngine::run()
{
	strategy->connect(first, second);
	return std::vector<std::unique_ptr<Connection>>();
}

std::unique_ptr<ConnectingStrategy> ConnectingEngine::evaluateStrategy()
{
	if (dynamic_cast<Layer2D*>(first.get()))
	{
		if (dynamic_cast<Layer2D*>(second.get()))
			return std::make_unique<MatrixToMatrix>();
		else return std::make_unique<MatrixToVector>();
	}
	else
	{
		if (dynamic_cast<Layer2D*>(second.get()))
			return std::make_unique<VectorToMatrix>();
		else return std::make_unique<VectorToVector>();
	}
}
