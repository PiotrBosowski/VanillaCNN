//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXCEPTIONS_H
#define VANILLACNN_CLION_EXCEPTIONS_H

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

class ContainerOutOfRangeException : public std::exception
{
public:
    ContainerOutOfRangeException();
};


#endif //VANILLACNN_CLION_EXCEPTIONS_H
