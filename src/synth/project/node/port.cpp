#include "port.hpp"

Port::Port(PortType type, const char* name)
{
    this->type = type;
    this->name = string(name);
}

PortType Port::getType()
{
    return this->type;
}

bool Port::isInput()
{
    return PortType::INPUT == this->type;
}