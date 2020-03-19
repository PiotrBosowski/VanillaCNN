#pragma once
#include "Neuron.h"
#include <memory>
#include "Container.h"
#include "ContainersConnectingStrategy.h"
#include "NeuronsConnectingStrategy.h"
#include <memory>

class Connector;

class Layer
{
public:
	Layer(int numberOfContainers);

protected:
	std::unique_ptr<ContainersConnectingStrategy> containersConnectingStrategy;
	std::shared_ptr<Layer> previousLayer;
	std::vector<std::unique_ptr<Container>> containers;
	int numberOfContainers;

public:
	void setPreviousLayer(std::shared_ptr<Layer> previousLayer);
	virtual std::vector<std::unique_ptr<Container>>& getContainers();
	virtual int getNumberOfContainers();
	virtual void createContainers() = 0;
	virtual void connectToPreceeding();
	virtual std::string getSummary();
};
