#include "Exceptions.h"

PopulatingException::PopulatingException(const char info[])
	: exception{info}
{
}

ConnectingException::ConnectingException(const char info[])
	: exception{ info }
{
}

CompilingException::CompilingException(const char info[])
	: exception{ info }
{
}

LayerCreatingException::LayerCreatingException(const char info[])
	: exception{ info }
{
}

ContainerOutOfRangeException::ContainerOutOfRangeException()
	: exception{ "Tried to access neurons beyond containers limits." }
{
}
