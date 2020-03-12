#pragma once

class Layer;

class Connector
{
public:
	virtual void connect(Layer& previousLayer) = 0;
	virtual void reportError(Layer& previousLayer);
};

