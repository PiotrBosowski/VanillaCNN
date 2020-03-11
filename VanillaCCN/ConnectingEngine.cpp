
#include "ConnectingEngine.h"
#include "Layer2D.h"
#include "Layer1D.h"
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

std::unique_ptr<ConnectingStrategy> ConnectingEngine::evaluateStrategy()
{
	if (dynamic_cast<Layer2D*>(&first) && dynamic_cast<Layer2D*>(&second))
		return std::make_unique<MatrixToMatrix>(); else
	if (dynamic_cast<Layer2D*>(&first) && dynamic_cast<Layer1D*>(&second))
		return std::make_unique<MatrixToVector>(); else
	if (dynamic_cast<Layer1D*>(&first) && dynamic_cast<Layer2D*>(&second))
		return std::make_unique<VectorToMatrix>(); else
	if (dynamic_cast<Layer1D*>(&first) && dynamic_cast<Layer1D*>(&second))
		return std::make_unique<VectorToVector>();
	else throw std::exception{ "error connecting layers" };
}
