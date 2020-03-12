#pragma once
#include <exception>

class PopulatingException : public std::exception
{
public:
	PopulatingException(const char info[]);
};

class ConnectingException : public std::exception
{
public:
	ConnectingException(const char info[]);
};

class CompilingException : public std::exception
{
public:
	CompilingException(const char info[]);
};

class LayerCreatingException : public std::exception
{
public:
	LayerCreatingException(const char info[]);
};