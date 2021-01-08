#include "connection.hpp"
#include "port.hpp"

using namespace Gale::Core;

Connection::Connection(Port* output, Port* input)
{
    this->output = output;
    this->input = input;
}

Port* Connection::getInput()
{
    return this->input;
}

Connection::~Connection()
{
    this->input->_removeConnection(this);
    this->output->_removeConnection(this);
}