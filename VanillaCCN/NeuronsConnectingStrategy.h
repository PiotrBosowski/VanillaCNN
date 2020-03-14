#pragma once

class Container;

class NeuronsConnectingStrategy
{
public:
	virtual void connect(Container& sourceContainer, Container& previousContainer) = 0;
};
