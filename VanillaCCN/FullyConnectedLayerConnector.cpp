#include "FullyConnectedLayerConnector.h"

FullyConnectedLayerConnector::FullyConnectedLayerConnector(FullyConnectedLayer& sourceLayer)
	: sourceLayer{sourceLayer}
{
}

void FullyConnectedLayerConnector::connect(Layer& previousLayer)
{
	//if() -> zidentyfikowanie polaczenia i oddelegowanie do odpowiedniej funkcji
}
