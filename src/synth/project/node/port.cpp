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

string Port::getName()
{
    return this->name;
}

Connection* Port::connect(Port* otherPort)
{
    // Connection between two inputs and two outputs is not allowed
    if (this->getType() == otherPort->getType())
    {
        return nullptr;
    }

    Port* output = this->isInput() ? otherPort : this;
    Port* input = this->isInput() ? this : otherPort;

    // Disallow more than one connection for input port
    if (input->getConnectionsCount() > 0)
    {
        return nullptr;
    }

    Connection* conn = new Connection(output, input);
    input->_addConnection(conn);
    output->_addConnection(conn);
}

unsigned short int Port::getConnectionsCount()
{
    return this->connections.size();
}

void Port::_addConnection(Connection* connection)
{
    this->connections.push_back(connection);
}