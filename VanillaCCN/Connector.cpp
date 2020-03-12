#include "Connector.h"
#include "Layer.h"

void Connector::reportError(Layer& previousLayer)
{
	std::string precedingLayerType = typeid(previousLayer).name();
	std::string followingLayerType = typeid(this).name();
	std::string report = "Can't connect new " + followingLayerType + " to already existing " + precedingLayerType + ".";
	throw std::exception(report.c_str());
}
