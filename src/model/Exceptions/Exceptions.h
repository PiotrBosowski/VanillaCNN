//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_EXCEPTIONS_H
#define VANILLACNN_CLION_EXCEPTIONS_H

#include <stdexcept>

class BaseException : public std::runtime_error
{
public:
    explicit BaseException(const char info[], const char details[] = "");
    const char *details() const;

private:
    const char* details_;

};

class LayerConnectingError : public BaseException {
public:
    explicit LayerConnectingError(const char* details = "");
};

class PopulatingException : public BaseException
{
public:
    explicit PopulatingException(const char* details = "");
};

class ConnectingException : public BaseException
{
public:
    explicit ConnectingException(const char* details = "");
};

class CompilingException : public BaseException
{
public:
    explicit CompilingException(const char* details = "");
};

class LayerCreatingException : public BaseException
{
public:
    explicit LayerCreatingException(const char* details = "");
};

class ContainerOutOfRangeException : public BaseException
{
public:
    explicit ContainerOutOfRangeException(const char* details = "");
};

class NetworkCreatingException : public BaseException
{
public:
    explicit NetworkCreatingException(const char* details = "");
};

class NeuronsConnectingException : public BaseException
{
public:
    explicit NeuronsConnectingException(const char* details = "");
};

class WeightsOutOfRangeError : public BaseException
{
public:
    explicit WeightsOutOfRangeError(const char* details = "");
};


#endif //VANILLACNN_CLION_EXCEPTIONS_H