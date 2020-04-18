//
// Created by piotr on 20/04/11.
//

#include "Exceptions.h"

PopulatingException::PopulatingException(const char* details)
        : BaseException{"Error populating the network", details}
{
}

ConnectingException::ConnectingException(const char* details)
        : BaseException{ "Error connecting neurons/layers", details }
{
}

CompilingException::CompilingException(const char* details)
        : BaseException{ "Error compiling the network", details }
{
}

LayerCreatingException::LayerCreatingException(const char* details)
        : BaseException{ "Error creating layer", details }
{
}

ContainerOutOfRangeException::ContainerOutOfRangeException(const char* details)
        : BaseException{ "Error accessing neurons beyond containers limits.", details }
{
}

BaseException::BaseException(const char *info, const char *details) : runtime_error(info), details_(details){

}

const char *BaseException::details() const {
    return details_;
}

NetworkCreatingException::NetworkCreatingException(const char *details)
: BaseException("Error creating network", details) {
}

LayerConnectingError::LayerConnectingError(const char *details)
    : BaseException{ "Error connecting Layers.", details }
{
}

NeuronsConnectingException::NeuronsConnectingException(const char *details)
: BaseException("Error during connecting Neurons") {

}

WeightsOutOfRangeError::WeightsOutOfRangeError(const char *details)
: BaseException("Error trying to access Weight beyond vector bounds") {
}
