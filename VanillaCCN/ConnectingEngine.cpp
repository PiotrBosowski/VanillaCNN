
#include "ConnectingEngine.h"
#include "Layer2D.h"
#include "Layer.h"
#include "ConnectingStrategy.h"
#include "MatrixToMatrix.h"
#include "MatrixToVector.h"
#include "VectorToMatrix.h"
#include "VectorToVector.h"
#include <memory>

ConnectingEngine::ConnectingEngine(Layer& first, Layer& second)
	: first{ first }, second{second}
{
	strategy = evaluateStrategy();
}

void ConnectingEngine::run()
{
	strategy->connect(first, second);
}

std::unique_ptr<ConnectingStrategy> ConnectingEngine::evaluateStrategy() //i dislike this function
{
	if (dynamic_cast<Layer2D*>(&first))
	{
		if (dynamic_cast<Layer2D*>(&second))
			return std::make_unique<MatrixToMatrix>();
		else return std::make_unique<MatrixToVector>();
	}
	else
	{
		if (dynamic_cast<Layer2D*>(&second))
			return std::make_unique<VectorToMatrix>();
		else return std::make_unique<VectorToVector>();
	}
}
