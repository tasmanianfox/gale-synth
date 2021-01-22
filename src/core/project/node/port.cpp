#include "port.hpp"

using namespace Gale::Core;

Port::Port(Node* node, PortType type, const char* name) :
    name(name),
    node(node),
    type(type),
    value(.0f) {}

PortType Port::getType()
{
    return this->type;
}

bool Port::isInput()
{
    return PortType::INPUT == this->type;
}

bool Port::isOutput()
{
    return PortType::OUTPUT == this->type;
}

string Port::getName()
{
    return this->name;
}

Node* Port::getNode()
{
    return this->node;
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
    return conn;
}

vector<Connection*> Port::getConnections()
{
    return this->connections;
}

unsigned short int Port::getConnectionsCount()
{
    return this->connections.size();
}

void Port::_addConnection(Connection* connection)
{
    this->connections.push_back(connection);
}

void Port::_removeConnection(Connection* connection)
{
    for (int i = 0; i < this->connections.size(); i++)
    {
        Connection* testConnection = this->connections.at(i);
        if (connection == testConnection)
        {
            this->connections.erase(this->connections.begin() + i);
            break;
        }
    }
}

Connection* Port::getConnection(int index)
{
    return this->connections.at(index);
}

void Port::deleteConnection(int index)
{
    Connection* connection = this->connections.at(index);
    this->connections.erase(this->connections.begin() + index, this->connections.begin() + index + 1);
    delete connection;
}

float Port::getValue() {
    return this->value;
}

void Port::setOutputValue(float value) {
    if (this->isInput()) {
        return;
    }
    this->value = value;
    for (Connection* connection: this->connections) {
        connection->getInput()->setInputValue(value);
    }
}

void Port::setInputValue(float value) {
    if (this->isOutput()) {
        return;
    }
    this->value = value;
}